#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "WiseAgent.generated.hpp"

namespace exampleModule
{

class WiseAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_become_wiser, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()

  void clearPreviousResult(ScAddr const & graph);
  void formingResult(ScAddrVector & answerElements, ScAddr const & graph);
  void getElements(ScAddrVector & answerElements, ScAddr const & graph, ScAddr const & node);
  bool nodeInGraph(ScAddr const & node, ScAddr const & graph);
};

}
