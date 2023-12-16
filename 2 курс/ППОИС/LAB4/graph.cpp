#include <iostream>
#include <vector>
#include <algorithm>


template<typename T>
class Graph_node{
private:
    T vertx;
public:
    
    Graph_node(T _vertx){
        vertx = _vertx;
    }

    bool operator==(const Graph_node<T>& other) const{
        return vertx == other.vertx;
    }

    T get_vertx() const{
        return vertx;
    }
    
};

template <typename T>
class VertIter{
private:
    using Vertex = Graph_node<T>;
    
public:
typename std::vector<std:: pair<Vertex, std::vector<Vertex>>>::iterator vertex_iter;
    using iterator_category = std:: bidirectional_iterator_tag;
    using value_type = Vertex;
    using difference_type = std::ptrdiff_t;
    using pointer = Vertex*;
    using reference = Vertex&;

    VertIter( typename std::vector<std:: pair<Vertex, std::vector<Vertex>>>::iterator _vertex_iter){
        vertex_iter = _vertex_iter;
    }

    VertIter& operator++(){
        ++vertex_iter;
        return *this;
    }

    VertIter operator++(int){
        VertIter temp = *this;
        ++(*this);
        return temp;
    }

    VertIter& operator--(){
        --vertex_iter;
        return *this;
    }

    VertIter operator--(int){
        VertIter temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const VertIter& other) const{
        return vertex_iter == other.vertex_iter;
    }

    bool operator!=(const VertIter& other) const{
        return !(vertex_iter == other.vertex_iter);
    }
    Vertex operator*(){
        return vertex_iter->first;
    }

    Vertex* operator->(){
       return &vertex_iter->first;
   }

};

template <typename T>
class EdgeIter{
private:
    using Vertex = Graph_node<T>;
    using Edge = std:: pair<Vertex, Vertex>;
    std::vector<std:: pair<Vertex, std::vector<Vertex>>> adjacency_list;
    // using AdjacencyList = std::vector<std::pair<Vertex, std::vector<Vertex>>>;

    // const AdjacencyList* adjacency_list; 
    // typename AdjacencyList::iterator vertex_iter; 
    typename std::vector<std:: pair<Vertex, std::vector<Vertex>>>::iterator vertex_iter;
    typename std::vector<Vertex>::iterator neighbour_iter;
public:

    using iterator_category = std:: bidirectional_iterator_tag;
    using value_type = Edge;
    using difference_type = std::ptrdiff_t;
    using pointer = Edge*;
    using reference = Edge&;

    EdgeIter(typename std::vector<std::pair<Vertex, std::vector<Vertex>>>::iterator _vertex_iter, std::vector<std::pair<Vertex, std::vector<Vertex>>>& _adjacency_list){
        vertex_iter = _vertex_iter;
        neighbour_iter = vertex_iter->second.begin();
        adjacency_list = _adjacency_list;
    }

    EdgeIter& operator++(){
        if (neighbour_iter != vertex_iter->second.end()){
            ++neighbour_iter;
            if (neighbour_iter == vertex_iter->second.end()){
                ++vertex_iter;
                if (vertex_iter != adjacency_list.end()){
                    neighbour_iter = vertex_iter->second.begin();
                }
            }
        }
        return *this;
    }

    EdgeIter operator++(int){
        EdgeIter temp = *this;
        ++(*this);
        return temp;
    }

    EdgeIter& operator--(){
        if (neighbour_iter != vertex_iter->second.begin()){
            --neighbour_iter;
        } else {
            if (vertex_iter != adjacency_list.begin()){
                --vertex_iter;
                neighbour_iter = vertex_iter->second.end();
            }
        }
        return *this;
    }

    EdgeIter operator--(int){
        EdgeIter temp = *this;
        --(*this);
        return *temp;
    }

    bool operator==(const EdgeIter& other) const{
        return vertex_iter == other.vertex_iter && neighbour_iter == other.neighbour_iter;
    }

    bool operator!=(const EdgeIter& other) const{
        return !(vertex_iter == other.vertex_iter) || !(neighbour_iter == other.neighbour_iter);
    }

    Edge operator*(){
        return std::make_pair(vertex_iter->first, *neighbour_iter);
    }

    Edge* operator->(){
       return &std::make_pair(vertex_iter->first, *neighbour_iter);
    }

    void print_adjacency_list2() {
        for (auto& adj_list : adjacency_list) {
            std::cout << "Vertex: " << adj_list.first.get_vertx() << std::endl;
            std::cout << "Neighbours: ";
            for (auto& neighbour : adj_list.second) {
                std::cout << neighbour.get_vertx() << " ";
            }
            std::cout << std::endl;
        }
    }
};

template <typename T>
class Graph{
private:
    using Vertex = Graph_node<T>;
    using Edge = std:: pair<Vertex, Vertex>;
    std:: vector<std::pair<Vertex ,std:: vector<Vertex>>> adjacency_list;
public: 
    
    VertIter<T> vbegin(){
        return VertIter<T>(adjacency_list.begin());
    }

    VertIter<T> vend(){
        return VertIter<T>(adjacency_list.end());
    }

    EdgeIter<T> ebegin(){
        return EdgeIter<T>(adjacency_list.begin(), adjacency_list);
    }

    EdgeIter<T> eend(){
        return EdgeIter<T>(adjacency_list.end(), adjacency_list);
    }
    
    Graph(){
        adjacency_list = {}; 
    }

    Graph(Vertex curr_vertx, std:: vector<Vertex> neighbours){
        adjacency_list = {{curr_vertx, neighbours}};
    }

    void add_vertex(Vertex _vertx){
        adjacency_list.push_back({_vertx, {}});
    }

    void add_edge(Edge now){
        for(int i = 0; i < adjacency_list.size(); i++){
            if (adjacency_list[i].first == now.first){
                adjacency_list[i].second.push_back(now.second);
            } 
        }
    }

private:
    void del_edge_wrapper(Vertex star, Vertex fin){
        for(auto& adj_list : adjacency_list)
            if(star == adj_list.first)
                for(auto j = adj_list.second.begin(); j != adj_list.second.end();){
                    if (fin == *j){
                        j = adj_list.second.erase(j);
                        return;
                    }
                    else ++j;
                }
        throw std:: logic_error("Delete element doesnot exist");
    }

public:
    void del_vertex(Vertex vert){
        for(auto i = adjacency_list.begin(); i != adjacency_list.end();){
            if (vert == i->first)
                i = adjacency_list.erase(i);
            else{
                for(auto j = i->second.begin(); j != i->second.end();){
                    if (vert == *j){
                        j = i->second.erase(j);
                    }
                    else ++j;
                }
                ++i;
            }
        }
    }

    void del_edge(Edge dele){
        del_edge_wrapper(dele.first, dele.second);
        del_edge_wrapper(dele.second, dele.first);
    }
    
    void print_adjacency_list() {
        for (auto& adj_list : adjacency_list) {
            std::cout << "Vertex: " << adj_list.first.get_vertx() << std::endl;
            std::cout << "Neighbours: ";
            for (auto& neighbour : adj_list.second) {
                std::cout << neighbour.get_vertx() << " ";
            }
            std::cout << std::endl;
        }
    }

    int vertex_degree(Vertex _curr){
        for(auto& adj_list: adjacency_list){
            if(adj_list == _curr){
                return adj_list.size() - 1;
            }
        }
    }

    int vertex_amount(){
        return adjacency_list.size();
    }
    void iter_del_edge(EdgeIter<T> it){
        it.vertex_iter->second.erase(it.neighbour_iter);
    } 
    void iter_del_vertex(VertIter<T> it){
   // Удаление всех ребер, связанных с вершиной
   for(auto& adj_list : adjacency_list) {
       adj_list.second.erase(std::remove_if(adj_list.second.begin(), adj_list.second.end(), [&it](const Vertex& v){ return v == *it; }), adj_list.second.end());
   }
   // Удаление вершины
   adjacency_list.erase(it.vertex_iter);
}

};

int main(){
    Graph<int> graph;

    // Создаем вершины
    Graph_node<int> node1(1);
    Graph_node<int> node2(2);
    Graph_node<int> node3(3);
    Graph_node<int> node4(4);

    // Добавляем вершины в граф
    graph.add_vertex(node1);
    graph.add_vertex(node2);
    graph.add_vertex(node3);
    graph.add_vertex(node4);

    std::pair<Graph_node<int>, Graph_node<int>> edge1(node1, node2);
    std::pair<Graph_node<int>, Graph_node<int>> edge2(node2, node3);
    std::pair<Graph_node<int>, Graph_node<int>> edge3(node3, node4);
    std::pair<Graph_node<int>, Graph_node<int>> edge4(node4, node1);

    graph.add_edge(edge1);
    graph.add_edge(edge2);
    graph.add_edge(edge3);
    graph.add_edge(edge4);

    graph.print_adjacency_list();
    for (auto it = graph.vbegin(); it != graph.vend(); ++it) {
        std::cout << "Vertex: " << it->get_vertx()<< std::endl;
    }

    for (auto it = graph.ebegin(); it != graph.eend(); ++it) {
        std::cout << "Edge: " << (*it).first.get_vertx() << " " << (*it).second.get_vertx()<< std::endl;
    }
    auto it = graph.vbegin();
    graph.iter_del_vertex(it);
    graph.print_adjacency_list();
    for (auto it = graph.vbegin(); it != graph.vend(); ++it) {
        std::cout << "Vertex: " << it->get_vertx()<< std::endl;
    }
    // for (auto it2 = graph.ebegin(); it2 != graph.eend(); ++it2) {
    //     std::cout << "Edge: " << (*it2).first.get_vertx() << " " << (*it2).second.get_vertx()<< std::endl;
    // }

    return 0;
}


