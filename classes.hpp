//
//  classes.h
//  ESPIM
//
//  Created by Lab. Mecanica Estruturas on 24/03/17.
//  Copyright © 2017 Lab. Mecanica Estruturas. All rights reserved.
//

#ifndef classes_h
#define classes_h

class Tria;	//forward declaration

class Node
{
public:
    int id;
    int index; // vai ser util quando for colocar esse nÛ na matriz global minimizando largura da banda
    double xyz[3];
    std::vector<Tria*> tria;
    Node() {};
    Node(int id, double x, double y, double z) : id(id)
    {
        xyz[0] = x;
        xyz[1] = y;
        xyz[2] = z;
    };
};


class Tria
{
public:
    Node n1;
    Node n2;
    Node n3;
    Tria(Node& n1, Node& n2, Node& n3) : n1(n1), n2(n2), n3(n3) {}
};


class Edge
{
public:
    Node n1;
    Node n2;
    std::vector<Tria*> trias;
    Edge(Node& n1, Node& n2) : n1(n1), n2(n2) {}
};






#endif /* classes_h */
