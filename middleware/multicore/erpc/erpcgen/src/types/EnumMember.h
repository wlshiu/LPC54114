/*
 * The Clear BSD License
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _EMBEDDED_RPC__ENUMMEBER_H_
#define _EMBEDDED_RPC__ENUMMEBER_H_

#include "Symbol.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////

namespace erpcgen {

/*!
 * @brief Member of a enum.
 */
class EnumMember : public Symbol
{
public:
    /*!
     * @brief Constructor.
     *
     * This function sets the value and token
     *
     * @param[in] tok Token, which contains name and location.
     * @param[in] value Given value.
     */
    EnumMember(const Token &tok, uint32_t value)
    : Symbol(kEnumMemberSymbol, tok)
    , m_value(value)
    {
    }

    /*!
     * @brief Constructor.
     *
     * This function set token to given token.
     *
     * @param[in] tok Token, which contains name and location.
     */
    EnumMember(const Token &tok)
    : Symbol(kEnumMemberSymbol, tok)
    , m_value(-1)
    {
    }

    /*!
     * @brief This function set enum member value.
     *
     * @param[in] value Value of enum member.
     */
    void setValue(IntegerValue value) { m_value = value; }

    /*!
     * @brief This function returns enum member value.
     *
     * @return String representation of enum member value.
     */
    uint32_t getValue() const { return (uint32_t)m_value; }

    /*!
     * @brief This function return true if enum member has set value.
     *
     * @retval true When enum member has set value.
     * @retval false When enum member has not set value.
     */
    bool hasValue() const { return -1 != (int32_t)m_value.getValue(); }

    /*!
     * @brief This function returns description about the enum member.
     *
     * @return String description about enum member.
     *
     * @see std::string AliasType::getDescription() const
     * @see std::string EnumType::getDescription() const
     * @see std::string StructMember::getDescription() const
     * @see std::string StructType::getDescription() const
     * @see std::string VoidType::getDescription() const
     * @see std::string ArrayType::getDescription() const
     * @see std::string ListType::getDescription() const
     * @see std::string UnionType::getDescription() const
     */
    virtual std::string getDescription() const;

protected:
    IntegerValue m_value; /*!< Integer value of enum member. */
};

} // namespace erpcgen

#endif // _EMBEDDED_RPC__ENUMMEBER_H_
