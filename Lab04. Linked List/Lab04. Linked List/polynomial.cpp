
// 2019112587_������

#include <iostream>
#include <cmath>
#include "listlnk.cpp"  // "include "listlnk.h"

using namespace std;

class PolyNode {
private:
    // Data members
    int coefficient;  //���
    int degree;       //����

public:
    PolyNode() {    // ������
        coefficient = 0;
        degree = 0;
    }
    PolyNode(int c, int d) {
        coefficient = c;
        degree = d;
    }

    //��� ��ȯ
    int getCoef() {
        return coefficient;
    }

    //���� ��ȯ
    int getDegree() {
        return degree; 
    }

    //��� ��ȯ
    void addCoef(int added) {
        coefficient += added;
    }
};

//c: coefficient, d: degree
void addTerm(List<PolyNode>* list, int c, int d) {

    PolyNode* nPoly;
    nPoly = new PolyNode(c, d); // pointer?
    if (list->isEmpty()) {
        list->insert(*nPoly);   // polynode�� ����Ű��
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
                else {  // next cursor�� 0�̶��(���� ���� ����)
                    list->insert(*nPoly);
                    break;
                }
            }
        } while (true);
    }
}


//���׽� ��� �Լ�
//c: coefficient, d: degree
void showPolynomial(List<PolyNode>& list) {
    if (list.isEmpty()) {
        cout << "Empty Polynomial" << endl;
    }
    else {
        list.gotoBeginning();   // ������ list�϶� ��� 
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
                         // if (!list.gotoPrior()){  --> �� ���̶�� ���̴ϱ�
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

