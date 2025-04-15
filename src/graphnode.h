#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>  // Add this for smart pointers
#include "chatbot.h"

// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to child nodes

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to parent nodes
    ChatBot _chatBot; // ChatBot instance is now owned by the node
    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    int GetNumberOfParents() { return _parentEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot chatbot);
    void MoveChatbotToNewNode(GraphNode *newNode);
    ////
    //// EOF STUDENT CODE
};

#endif /* GRAPHNODE_H_ */