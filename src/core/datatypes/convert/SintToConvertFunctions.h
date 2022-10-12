/*******************************************************************************
 * Copyright (c) 2010 - 2015 TU Vienna/ACIN, Profactor GmbH, fortiss GmbH,
 *    2018-2019 TU Vienna/ACIN
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Alois Zoitl, Ingo Hegny, Monika Wenger, Carolyn Oates, Patrick Smejkal,
 *    Matthias Plasch,
 *      - initial implementation and rework communication infrastructure
 *    Martin Melik-Merkumians - fixes DT_TO_TOD
 *    Martin Melik-Merkumians - removes invalid casts, update implementation
 *     to use new cast function
 *******************************************************************************/

#ifndef SRC_CORE_DATATYPES_CONVERT_SINTTOCONVERTFUNCTIONS_H_
#define SRC_CORE_DATATYPES_CONVERT_SINTTOCONVERTFUNCTIONS_H_

//********************************************************************************************
//   SINT_TO_*  functions
//********************************************************************************************
inline const CIEC_BYTE func_SINT_TO_BYTE(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_BYTE>(paVal);
}

inline const CIEC_DWORD func_SINT_TO_DWORD(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_DWORD>(paVal);
}

inline const CIEC_DINT func_SINT_TO_DINT(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_DINT>(paVal);
}

inline const CIEC_LINT func_SINT_TO_LINT(const CIEC_SINT &paVal){
  return CIEC_ANY::cast<CIEC_LINT>(paVal);
}

#ifdef FORTE_USE_LREAL_DATATYPE
inline const CIEC_LREAL func_SINT_TO_LREAL(const CIEC_SINT &paVal){
  return CIEC_ANY::cast<CIEC_LREAL>(paVal);
}
#endif

inline const CIEC_LWORD func_SINT_TO_LWORD(const CIEC_SINT &paVal){
  return CIEC_ANY::cast<CIEC_LWORD>(paVal);
}

#ifdef FORTE_USE_REAL_DATATYPE
inline const CIEC_REAL func_SINT_TO_REAL(const CIEC_SINT &paVal){
  return CIEC_ANY::cast<CIEC_REAL>(paVal);
}
#endif

inline const CIEC_INT func_SINT_TO_INT(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_INT>(paVal);
}

inline const CIEC_UDINT func_SINT_TO_UDINT(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_UDINT>(paVal);
}

inline const CIEC_UINT func_SINT_TO_UINT(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_UINT>(paVal);
}

inline const CIEC_ULINT func_SINT_TO_ULINT(const CIEC_SINT &paVal){
  return CIEC_ANY::cast<CIEC_ULINT>(paVal);
}

inline const CIEC_USINT func_SINT_TO_USINT(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_USINT>(paVal);
}

inline const CIEC_WORD func_SINT_TO_WORD(const CIEC_SINT &paVal) {
  return CIEC_ANY::cast<CIEC_WORD>(paVal);
}

inline const CIEC_STRING func_SINT_TO_STRING(const CIEC_SINT &paVal) {
  CIEC_STRING string;
  stringConverter(string, paVal);
  return string;
}

#ifdef FORTE_USE_WSTRING_DATATYPE
inline const CIEC_WSTRING func_SINT_TO_WSTRING(const CIEC_SINT &paVal){
  CIEC_WSTRING string;
  stringConverter(string, paVal);
  return string;
}
#endif

#endif /* SRC_CORE_DATATYPES_CONVERT_SINTTOCONVERTFUNCTIONS_H_ */
