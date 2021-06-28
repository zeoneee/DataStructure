//--------------------------------------------------------------------
//
//  Laboratory 14                                          wtgraph.cpp
//
//  Implementation of the Weighted Graph ADT
//
//--------------------------------------------------------------------
#include "wtgraph.h"
#include <iostream>

//--------------------------------------------------------------------

// 2019112587 김지현

WtGraph::WtGraph(int maxNumber)
{
    maxSize = maxNumber;
    size = 0;
    vertexList = new Vertex[maxSize];
    adjMatrix = new int[maxSize * maxSize];
    pathMatrix = new int[maxSize * maxSize];
}

WtGraph::~WtGraph()
{
    delete[] vertexList;
    delete[] adjMatrix;
    delete[] pathMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(vertexList[i].label, v) == 0)
            return i;
    }
}

int WtGraph::getEdge(int row, int col)
{
    return adjMatrix[maxSize * row + col];
}

void WtGraph::setEdge(int row, int col, int wt)
{
    adjMatrix[maxSize * row + col] = wt;
}

//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex)
{
    if (isFull()) {
        cout << "Graph is full" << endl;
    }
    else {
        vertexList[size] = newVertex;
        size++;
    }
}

void WtGraph::insertEdge(char* v1, char* v2, int wt)
{
    Vertex v_1, v_2;
    if (retrieveVertex(v1, v_1) && retrieveVertex(v2, v_2)) {
        int row = getIndex(v1);
        int col = getIndex(v2);
        setEdge(row, col, wt);
        setEdge(col, row, wt);
    }
    else {
        cout << "wrong Vertex" << endl;
    }
}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(vertexList[i].label, v) == 0) {
            vData = vertexList[i];
            return true;
        }
    }
    return false;
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt)
{
    // 두 정점사이에 간선이 연결되어있는지
    int row = getIndex(v1);
    int col = getIndex(v2);
    wt = getEdge(row, col);
    if (wt == infiniteEdgeWt) return false;
    else return true;
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v)
{
    // 정점이 사라지는거니까 간선들도 다 삭제돼어야함
    int idx = getIndex(v), i, j;
    for (i = idx; i < (size - 1); i++) {
        vertexList[i] = vertexList[i + 1];
    }
    for (i = idx; i < (size - 1); i++) {
        for (j = 0; j < size; j++) {
            setEdge(i, j, getEdge(i + 1, j));
        }
    }
    for (i = idx; i < (size - 1); i++) {
        for (j = 0; j < size; j++) {
            setEdge(j, i, getEdge(j, i + 1));
        }
    }
    size--;
}

void WtGraph::removeEdge(char* v1, char* v2)
{
    Vertex v_1, v_2;
    if (retrieveVertex(v1, v_1) && retrieveVertex(v2, v_2)) {
        int row = getIndex(v1);
        int col = getIndex(v2);
        setEdge(row, col, infiniteEdgeWt);
        setEdge(col, row, infiniteEdgeWt);
    }
    else {
        cout << "wrong Vertex" << endl;
    }
}

//--------------------------------------------------------------------

void WtGraph::clear()
{
    size = 0;
    for (int i = 0; i < maxSize * maxSize; i++) {
        adjMatrix[i] = infiniteEdgeWt;
        pathMatrix[i] = infiniteEdgeWt;
    }
}

bool WtGraph::isEmpty() const
{
    return(size == 0);
}

bool WtGraph::isFull() const
{
    return(size == maxSize);
}

//--------------------------------------------------------------------

void WtGraph::showStructure()

// Outputs a graph's vertex list (w/ color) and adjacency matrix.
// This operation is intended for testing/debugging purposes only.

{
    int wt,         // Edge weight
        row, col;   // Loop counters

    if (size == 0)
        cout << "Empty graph" << endl;
    else
    {
        cout << endl << "Vertex list : " << endl;
        for (row = 0; row < size; row++)
            cout << row << '\t' << vertexList[row].label << endl;

        cout << endl << "Edge matrix : " << endl << '\t';
        for (col = 0; col < size; col++)
            cout << col << '\t';
        cout << endl;
        for (row = 0; row < size; row++)
        {
            cout << row << '\t';
            for (col = 0; col < size; col++)
            {
                wt = getEdge(row, col);
                if (wt == infiniteEdgeWt)
                    cout << "- \t";
                else
                    cout << wt << '\t';
            }
            cout << endl;
        }

        cout << endl << "Path matrix : " << endl << '\t';
        for (col = 0; col < size; col++)
            cout << col << '\t';
        cout << endl;
        for (row = 0; row < size; row++)
        {
            cout << row << '\t';
            for (col = 0; col < size; col++)
            {
                wt = getPath(row, col);
                if (wt== 0)
                    cout << "- \t";
                else
                    cout << wt << '\t';
            }
            cout << endl;
        }
    }
}

//--------------------------------------------------------------------
//int* pathMatrix;

 int WtGraph::getPath(int row, int col)
 {
     return pathMatrix[maxSize * row + col];
 }

 void WtGraph::setPath(int row, int col, int wt) {
    pathMatrix[maxSize * row + col] = wt;
 }

 void WtGraph::computePaths() 
 {
     for (int i = 0; i < size; i++) { // 우선 여기서 0으로 세팅 
         for (int j = 0; j < size; j++) {
             if (getEdge(i, j) == infiniteEdgeWt) {
                 setPath(i, j, 0);
             }
             else {
                 setPath(i, j, getEdge(i, j));
             }
         }
     }
       
     for (int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++) {
             for (int k = 0; k < size; k++) {
                 if (getPath(j, i) != 0 && getPath(i, k) != 0) {
                     if (getPath(j, k) == 0 || getPath(j, k) > getPath(j, i) + getPath(i, k))
                     {
                         if (j != k)    // j==k라면 0이 맞으니까 
                         {
                             setPath(j, k, getPath(j, i) + getPath(i, k));
                             setPath(k, j, getPath(j, i) + getPath(i, k));
                         }
                     }
                 }
             }
         }
     }
 }