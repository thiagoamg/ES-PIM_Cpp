// bibs
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>      
#include <vector>
#include <stdlib.h>
#include "classes.hpp"
#include <algorithm>
#include <iterator>

// general declaration
using namespace std;
int ind;


// begining main
int main () {
    std::string line;
    std::vector <double> posx, posy, posz;
    std::vector<Node> node;
    std::vector<Tria> tria;
    std::vector<Edge> edge;

    int i, j, aux, count, n1, n2, n3;
    
    
    
    // reading posx from file from matlab
    ifstream myfile ("/Users/LMest/Dropbox/Congressos/MeshLESS/x.dat");
    if (myfile.is_open())
    {
        ind=0;
        while ( getline (myfile,line) )
        {
            std::istringstream s(line);
            std::string field;
            while (getline(s, field,',')){
                posx.push_back(std::stod(field));
                posz.push_back(0.0);
                ind+=1;
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    
    
    // reading posy from file from matlab
    ifstream myfile1 ("/Users/LMest/Dropbox/Congressos/MeshLESS/y.dat");
    if (myfile1.is_open())
    {
        ind=0;
        while ( getline (myfile1,line) )
        {
            std::istringstream s(line);
            std::string field;
            while (getline(s, field,',')){
                posy.push_back(std::stod(field));
                ind+=1;
            }
        }
        myfile1.close();
    }
    else cout << "Unable to open file";
    
    
    // Nodes Declaration
    for (i = 0; i < posy.size(); i++){
        node.push_back({i+1 , posx[i], posy[i], posz[i]});
    }

    cout << "Node = " << node[1].id << "\n";
    n1=0;
    n2=0;
    n3=0;
    
    // reading trias
    ifstream tria_file ("/Users/LMest/Dropbox/Congressos/MeshLESS/tria.dat");
    if (tria_file.is_open())
    {
        ind=0;
        while ( getline (tria_file,line) )
        {
            std::istringstream s(line);
            std::string field;
            aux=0;
            while (getline(s, field,',')){
                aux+=1;
                if (aux == 1)
                    n1 = std::stoi(field);
                if (aux == 2)
                    n2 = std::stoi(field);
                if (aux == 3)
                    n3 = std::stoi(field);
            }
            vector<int> auxn = {n1,n2,n3};
            sort(auxn.begin(), auxn.end());
            

            tria.push_back({node[n1],node[n2],node[n3]});
            
            //cout << "Tria " << ind <<", " << auxn[0] << ", " << auxn[1] << ", " << auxn[2];
            //cout << endl;
            ind+=1;
        }
        tria_file.close();
    }
    
        
    cout << "\n\n";
//
//
//    
//    // finding the number of trias in each node
//    for (j = 0; j < node.size(); j++){
//        count=0;
//        for (i = 0; i < tria.size(); i++){
//            if (tria[i]._n1 == node[j]._id || tria[i]._n2 == node[j]._id || tria[i]._n3 == node[j]._id)
//                count+=1;
//        }
//        node[j]._ntrias=count;
//        //cout << "Node " << node[j]._id << " ntrias "<< count;
//        //cout << endl;
//    }
//
//
    // Constructing Edges
    for (i=0 ; i < tria.size() ; i++){
            edge.push_back({tria[i].n1,tria[i].n2});
            edge.push_back({tria[i].n1,tria[i].n3});
            edge.push_back({tria[i].n2,tria[i].n3});
    }
    

//    for (i=0 ; i < edge.size() ; i++){
//            for (j=0 ; j < edge.size() ; j++){
//                if ( i!= j && edge[i].n1 == edge[j].n1 && edge[i].n2 == edge[j].n2  )
//                    edge.erase(edge.begin()+i);
//                if ( i!=j && edge[i].n1 == edge[j].n2 && edge[i].n2 = edge[j].n1  )
//                    edge.erase(edge.begin()+i);
//            }
//    }

    
    
    return 0;
}