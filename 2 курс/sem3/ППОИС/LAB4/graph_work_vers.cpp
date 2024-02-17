#include <iostream>
#include <vector>

template<typename T>
class Graph_node{
private:
    T vertx;
public:
    Graph_node(){
        vertx = 0;
    }

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
class Graph{
private:
    using Vertex = Graph_node<T>;
    using Edge = std:: pair<Vertex, Vertex>;
    std:: vector<std::pair<Vertex ,std:: vector<Vertex>>> adjacency_list;
public: 
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

    void vertex_degree(Vertex _curr){
        for(auto& adj_list: adjadency_list){
            if(adj_list == _curr){
                return adj_list.size() - 1;
            }
        }
    }

    void vertex_amount(){
        return adjacency_list.size();
    }

};

int main(){
    Graph<int> test;
    test.add_vertex(2);
    test.add_vertex(3);
    test.add_edge({2,3});
    test.add_edge({3, 2});
    test.print_adjacency_list();
    test.del_vertex(2);
    test.print_adjacency_list();
    return 0;
}