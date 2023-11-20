#include <sc-agents-common/utils/GenerationUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/IteratorUtils.hpp>

#include "WiseAgent.hpp"

using namespace std;
using namespace utils;

namespace exampleModule
{

SC_AGENT_IMPLEMENTATION(WiseAgent)
{
    ScAddr actionNode = otherAddr;
    ScAddr graph = IteratorUtils::getAnyFromSet(ms_context.get(), actionNode);

    if (!graph.IsValid())
    {
        SC_LOG_ERROR("CycleCheckAgent:  Invalid argument");
        utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, false);
        return SC_RESULT_ERROR_INVALID_PARAMS;
    }

    ScAddrVector answerElements;

    try
    {
        formingResult(answerElements, graph);
    }
    catch (exception & exc)
    {
        SC_LOG_ERROR("CycleCheckAgent:  " << exc.what());
        utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, false);
        return SC_RESULT_ERROR;
    }

    utils::AgentUtils::finishAgentWork(ms_context.get(), actionNode, answerElements, true);
    return SC_RESULT_OK;
}

void WiseAgent::clearPreviousResult(ScAddr const & graph){
    ScIterator5Ptr it5 = m_memoryCtx.Iterator5(
            graph,
            ScType::EdgeDCommonConst,
            ScType::NodeConstStruct,
            ScType::EdgeAccessConstPosPerm,
            Keynodes::nrel_wise_result);
    while (it5->Next()) {
        ScIterator3Ptr it3 = m_memoryCtx.Iterator3(
                ScType::Unknown,
                ScType::EdgeAccessConstPosPerm,
                it5->Get(2));
        while (it3->Next())
            m_memoryCtx.EraseElement(it3->Get(1));

        m_memoryCtx.EraseElement(it5->Get(1));
        m_memoryCtx.EraseElement(it5->Get(2));
    }
}

void WiseAgent::formingResult(ScAddrVector & answerElements, ScAddr const & graph) {
    clearPreviousResult(graph);

    ScIterator3Ptr it3 = m_memoryCtx.Iterator3(
            graph,
            ScType::EdgeAccessConstPosPerm,
            ScType::NodeConst);

    while (it3->Next()) {
        if (find(answerElements.begin(), answerElements.end(), it3->Get(2)) == answerElements.end())
            getElements(answerElements, graph, it3->Get(2));
    }

    ScAddrVector subElements;

    ScAddr const & resultStruct = m_memoryCtx.CreateNode(ScType::NodeConstStruct);
    subElements.push_back(resultStruct);

    ScAddr const & classEdge = m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm,
                                                      Keynodes::spanning_tree_set, resultStruct);
    subElements.push_back(classEdge);

    ScAddr const & relationArc = m_memoryCtx.CreateEdge(ScType::EdgeDCommonConst, graph, resultStruct);
    subElements.push_back(relationArc);
    ScAddr const & relationAccessArc = m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm,
                                                              Keynodes::nrel_wise_result, relationArc);
    subElements.push_back(relationAccessArc);

    for (auto object : answerElements) {
        ScAddr const & arc = m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm,
                                                                  resultStruct, object);
        subElements.push_back(arc);
    }

    answerElements.insert(answerElements.end(), subElements.begin(), subElements.end());
}

void WiseAgent::getElements(ScAddrVector & answerElements, ScAddr const & graph, ScAddr const & node) {
    answerElements.push_back(node);

    ScIterator5Ptr it5_1 = m_memoryCtx.Iterator5(node,
                                                 ScType::Unknown,
                                                 ScType::NodeConst,
                                                 ScType::EdgeAccessConstPosPerm,
                                                 graph);
    while (it5_1->Next()) {
        ScAddr currentNode = it5_1->Get(2);

        if (!nodeInGraph(currentNode, graph))
            continue;

        if (find(answerElements.begin(), answerElements.end(), currentNode) != answerElements.end())
            continue;

        answerElements.push_back(it5_1->Get(1));
        getElements(answerElements, graph, currentNode);
    }

    ScIterator5Ptr it5_2 = m_memoryCtx.Iterator5(ScType::NodeConst,
                                                 ScType::Unknown,
                                                 node,
                                                 ScType::EdgeAccessConstPosPerm,
                                                 graph);
    while (it5_2->Next()) {
        ScAddr currentNode = it5_2->Get(0);

        if (!nodeInGraph(currentNode, graph))
            continue;

        if (find(answerElements.begin(), answerElements.end(), currentNode) != answerElements.end())
            continue;

        answerElements.push_back(it5_2->Get(1));
        getElements(answerElements, graph, currentNode);
    }
}

bool WiseAgent::nodeInGraph(ScAddr const & node, ScAddr const & graph) {
    ScIterator3Ptr it3 = m_memoryCtx.Iterator3(
            graph,
            ScType::EdgeAccessConstPosPerm,
            node);

    if (it3->Next())
        return true;

    return false;
}

}
