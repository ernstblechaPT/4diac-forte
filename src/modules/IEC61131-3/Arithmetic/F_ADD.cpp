/*******************************************************************************
 * Copyright (c) 2011 - 2013 ACIN, fortiss GmbH
 *               2023 Martin Erich Jobst
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Monika Wenger, Alois Zoitl
 *   - initial API and implementation and/or initial documentation
 *   Martin Jobst
 *     - refactor for ANY variant
 *******************************************************************************/

#include "F_ADD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_ADD_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"

DEFINE_FIRMWARE_FB(FORTE_F_ADD, g_nStringIdF_ADD)

const CStringDictionary::TStringId FORTE_F_ADD::scm_anDataInputNames[] = {g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_F_ADD::scm_anDataInputTypeIds[] = {g_nStringIdANY_MAGNITUDE, g_nStringIdANY_MAGNITUDE};

const CStringDictionary::TStringId FORTE_F_ADD::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_ADD::scm_anDataOutputTypeIds[] = {g_nStringIdANY_MAGNITUDE};

const TDataIOID FORTE_F_ADD::scm_anEIWith[] = {0, 1, 255};
const TForteInt16 FORTE_F_ADD::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_ADD::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_ADD::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_ADD::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_ADD::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_F_ADD::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  2, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

FORTE_F_ADD::FORTE_F_ADD(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
    CFunctionBlock( pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId),
    var_IN1(CIEC_ANY_MAGNITUDE_VARIANT()),
    var_IN2(CIEC_ANY_MAGNITUDE_VARIANT()),
    var_OUT(CIEC_ANY_MAGNITUDE_VARIANT()),
    var_conn_OUT(var_OUT),
    conn_CNF(this, 0),
    conn_IN1(nullptr),
    conn_IN2(nullptr),
    conn_OUT(this, 0, &var_conn_OUT) {
};

void FORTE_F_ADD::executeEvent(int pa_nEIID) {
  switch(pa_nEIID) {
    case scm_nEventREQID:
      var_OUT = std::visit([](auto &&paIN1, auto&&paIN2) -> CIEC_ANY_MAGNITUDE_VARIANT {
        using T = std::decay_t<decltype(paIN1)>;
        using U = std::decay_t<decltype(paIN2)>;
        using deductedType = typename forte::core::mpl::get_add_operator_result_type<T, U>::type;
        if constexpr (!std::is_same<deductedType, forte::core::mpl::NullType>::value) {
          return func_ADD(paIN1, paIN2);
        }
        DEVLOG_ERROR("Adding incompatible types %s and %s\n",
                     CStringDictionary::getInstance().get(paIN1.getTypeNameID()),
                     CStringDictionary::getInstance().get(paIN2.getTypeNameID()));
        return CIEC_ANY_MAGNITUDE_VARIANT();
      }, var_IN1, var_IN2);
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

void FORTE_F_ADD::readInputData(size_t pa_nEIID) {
  switch(pa_nEIID) {
    case scm_nEventREQID: {
      CCriticalRegion criticalRegion(getResource().m_oResDataConSync);
      readData(0, &var_IN1, conn_IN1);
      readData(1, &var_IN2, conn_IN2);
      break;
    }
    default:
      break;
  }
}

void FORTE_F_ADD::writeOutputData(size_t pa_nEIID) {
  switch(pa_nEIID) {
    case scm_nEventCNFID: {
      CCriticalRegion criticalRegion(getResource().m_oResDataConSync);
      writeData(0, &var_OUT, &conn_OUT);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_F_ADD::getDI(size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_IN1;
    case 1: return &var_IN2;
  }
  return nullptr;
}

CIEC_ANY *FORTE_F_ADD::getDO(size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_OUT;
  }
  return nullptr;
}

CEventConnection *FORTE_F_ADD::getEOConUnchecked(TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_F_ADD::getDIConUnchecked(TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_IN1;
    case 1: return &conn_IN2;
  }
  return nullptr;
}

CDataConnection *FORTE_F_ADD::getDOConUnchecked(TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_OUT;
  }
  return nullptr;
}


