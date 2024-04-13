#include <vector>
#include <unordered_map>
#include <Eigen/Dense>



template <typename T> 
struct Node
{
  char key;
  T value;
  Node(char _key, T _value): key(_key), value(_value){}
};

class Graph
{
  public:

    /**
     * 
     * @brief  just because a -> b, doesn't mean b -> a:w
     */
    int AddEdge(char _src, char _dst)
    {
      int srcIdx = 0;
      int dstIdx = 0;
      try
      {
        srcIdx = keyToIdx_.at(_src);
        dstIdx = keyToIdx_.at(_dst);
      }
      catch(const std::out_of_range &oor)
      {
        return -1;
      }
      
      adjacentList_(srcIdx,dstIdx) = 1;
      return 0; 
    }
   
    int GetEdgeStatus(char _src, char _dst)
    {
      int srcIdx = 0;
      int dstIdx = 0;
      try
      {
        srcIdx = keyToIdx_.at(_src);
        dstIdx = keyToIdx_.at(_dst);
      }
      catch(const std::out_of_range &oor)
      {
        return -1;
      }
      return adjacentList_(srcIdx,dstIdx); 
    }
  
    void AddNode(char _node)
    {
      keyToIdx_[_node] = nodeList_.size(); //store string key and idx into list
      nodeList_.push_back(Node<int>(_node,0));
      adjacentList_ = adjacentList_.Zero(GetNodeList().size(), GetNodeList().size());
    }  

    inline std::vector<Node<int>>
    GetNodeList() const 
    {
      return nodeList_;
    }
  
    void PrintAdjacency()
    {

      std::cerr<<' '; 
      for(auto n: nodeList_)
        std::cerr<< n.key;
      std::cerr<<std::endl;
      for(int i = 0 ; i <nodeList_.size(); i++)
      {
        std::cerr<< nodeList_.at(i).key;
        for(int j = 0 ; j <nodeList_.size(); j++)
        {
          std::cerr<<adjacentList_(i,j);
        } 
        std::cerr<<std::endl;
      } 
    }  


  private:
    std::vector<Node<int>> nodeList_;
    std::unordered_map<char,int> keyToIdx_;
    Eigen::MatrixXi adjacentList_;
};

