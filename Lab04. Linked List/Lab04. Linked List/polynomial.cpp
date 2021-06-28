
// 2019112587_김지현

#include <iostream>
#include <cmath>
#include "listlnk.cpp"  // "include "listlnk.h"

using namespace std;

class PolyNode {
private:
    // Data members
    int coefficient;  //계수
    int degree;       //차수

public:
    PolyNode() {    // 생성자
        coefficient = 0;
        degree = 0;
    }
    PolyNode(int c, int d) {
        coefficient = c;
        degree = d;
    }

    //계수 반환
    int getCoef() {
        return coefficient;
    }

    //차수 반환
    int getDegree() {
        return degree; 
    }

    //계수 변환
    void addCoef(int added) {
        coefficient += added;
    }
};

//c: coefficient, d: degree
void addTerm(List<PolyNode>* list, int c, int d) {

    PolyNode* nPoly;
    nPoly = new PolyNode(c, d); // pointer?
    if (list->isEmpty()) {
        list->insert(*nPoly);   // polynode가 가리키는
    }
    else {
        list->gotoBeginning();
        do {
            if (list->getCursor().getDegree() == d) {
                list->getCursor().addCoef(c);
                break;
            }
            else if (list->getCursor().getDegree() < d) {
                list->insertBefore(*nPoly);
                break;
            }
            else if (list->getCursor().getDegree() > d) {
                if (list->gotoNext()) {
                    continue;
                }
                else {  // next cursor가 0이라면(제일 작은 차수)
                    list->insert(*nPoly);
                    break;
                }
            }
        } while (true);
    }
}


//다항식 출력 함수
//c: coefficient, d: degree
void showPolynomial(List<PolyNode>& list) {
    if (list.isEmpty()) {
        cout << "Empty Polynomial" << endl;
    }
    else {
        list.gotoBeginning();   // 마지막 list일때 고려 
         do{
                 if (list.getCursor().getCoef() == 1) {
                     if (list.getCursor().getDegree() == 0) {
                         cout << " + " << list.getCursor().getCoef();
                     }
                     else {
                         cout << " + x^" << list.getCursor().getDegree();
                     }
                 }
                 else if (list.getCursor().getCoef() == 0) {
                     continue;
                 }
                 else {
                     if (list.getCursor().getDegree() == 0) {
                         // if (!list.gotoPrior()){  --> 맨 앞이라는 뜻이니까
                         // cout<< list.getCursor().getCoef(); 
                         cout << " + " << list.getCursor().getCoef();
                     }
                     else {
                         cout << " + " << list.getCursor().getCoef()
                             << "x^" << list.getCursor().getDegree();
                     }
                 }
         } while (list.gotoNext());
         cout << endl;
    }
}

void main()
{
    List<PolyNode> testList;   // Test list
    int coef, degree;          // List data item
    char cmd;                  // Input command

    do
    {
        showPolynomial(testList);                     // Output list

        // cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if (cmd == '+' || cmd == '-')
            cin >> degree >> coef;

        switch (cmd)
        {
        case '+':                                  // insert
            addTerm(&testList, coef, degree);
            break;

        case '-':                                  // remove
            coef *= -1;
            addTerm(&testList, coef, degree);
            break;

        case 'C': case 'c':                       // clear
            testList.clear();
            break;

        case 'Q': case 'q':                   // Quit test program
            break;

        default:                               // Invalid command
            cout << "Inactive or invalid command" << endl;
        }
    } while (cmd != 'Q' && cmd != 'q');
}

