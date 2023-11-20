/*
 * This source file is part of an OSTIS project. For the latest info, see
 * http://ostis.net Distributed under the MIT License (See accompanying file
 * COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#pragma once

#include <sc-memory/sc_addr.hpp>
#include <sc-memory/sc_object.hpp>

#include "keynodes.generated.hpp"

namespace exampleModule
{
class Keynodes : public ScObject
{
  SC_CLASS()
  SC_GENERATED_BODY()

public:
  SC_PROPERTY(Keynode("question_become_wiser"), ForceCreate)
  static ScAddr question_become_wiser;
  
  SC_PROPERTY(Keynode("nrel_wise_result"), ForceCreate)
  static ScAddr nrel_wise_result;
  
  SC_PROPERTY(Keynode("spanning_tree_set"), ForceCreate)
  static ScAddr spanning_tree_set;
};

}  // namespace exampleModule
