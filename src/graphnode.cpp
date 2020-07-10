#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // Task 0. debug segmentation
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
// {
//     _childEdges.push_back(edge);
// }

// (7/10) Task 3.
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge)); //task 4
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // return _childEdges[index];

    // (7/10) Task3: 
    // unique_ptr without loss of ownership just return the pointer register
    // _childEdges is unique_ptr
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}