#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Vertex {
    string data;
    int index;
    struct Vertex* Next;
    struct Edge* Elist;
};

struct Edge {
    //int weight;
    struct Vertex* ToVertex;
    struct Edge* next;
};

struct Vertex* Cstart = NULL;

//=======================================insert functions====================================
int Vcount = 0;

string intToString(int value) {
    if (value == 0) {
        return "0";
    }

    std::string result;
    bool isNegative = false;

    if (value < 0) {
        isNegative = true;
        value = -value;
    }

    while (value > 0) {
        int digit = value % 10;
        result = static_cast<char>('0' + digit) + result;
        value /= 10;
    }

    if (isNegative) {
        result = "-" + result;
    }

    return result;
}


void InsertVertex(string c) {
    struct Vertex* temp = new Vertex;
    temp->data = c;
    temp->Next = NULL;
    temp->Elist = NULL;
    temp->index = Vcount;
    Vcount += 1;
    if (Cstart == NULL) {
        Cstart = temp;
    }
    else {
        struct Vertex* current = Cstart;
        while (current->Next != NULL) {
            current = current->Next;
        }
        current->Next = temp;
    }
}

void InsertEdge(string c, string sub) {
    Vertex* curr1 = Cstart;// for if the vertex exist from which we want to connect
    while (curr1 != NULL) {
        if (curr1->data == c) {
            Vertex* curr2 = Cstart;// for if the vertex which we want to connect to exists
            while (curr2 != NULL)
            {
                if (curr2->data == sub)
                {
                    Edge* temp = new Edge;
                    temp->ToVertex = curr2;
                    temp->next = NULL;
                    if (curr1->Elist == NULL) {
                        curr1->Elist = temp;
                        cout << "Edge is successfully linked with vertex" << endl;
                        cout << "when null\n";
                        return;
                    }
                    else {
                        struct Edge* Ecurr = curr1->Elist;
                        while (Ecurr->next != NULL) {
                            Ecurr = Ecurr->next;
                        }
                        Ecurr->next = temp;
                        cout << "Edge is successfully enrolled in course" << endl;
                        cout << "when not null\n";
                        return;
                    }

                }
                curr2 = curr2->Next;
            }
            if (curr2 == NULL)
            {
                cout << "the other vertex is not in list...\n";
                return;
            }
        }
        curr1 = curr1->Next;
    }
    if (curr1 == NULL) {
        cout << "Vertex not found" << endl;
        return;
    }

}
//=====================================printing functions==============================================
void PrintVertex() {
    Vertex* ptr = Cstart;
    if (ptr == NULL) cout << "empty" << endl;
    while (ptr != NULL) {
        cout << ptr->data << endl;
        ptr = ptr->Next;
    }
}

void PrintEdge() {
    string vertex;
    cout << "Enter the vertex number: ";
    cin >> vertex;
    Vertex* current = Cstart;
    if (current == NULL) {
        cout << "vertex does not exist" << endl;
    }
    while (current != NULL) {
        if (current->data == vertex) {
            Edge* ptr = current->Elist;
            if (ptr == NULL) {
                cout << "empty" << endl;
                return;
            }
            while (ptr != NULL) {
                cout << ptr->ToVertex->data << endl;
                ptr = ptr->next;
            }
            return;
        }
        current = current->Next;
        if (current == NULL)cout << "course does not exist" << endl;
    }
}

void printgraph() {
    struct Vertex* current = Cstart;
    if (current == NULL) {
        cout << "Linked List is empty";
    }
    else {
        while (current != NULL) {
            cout << "Vertex : " << current->data << endl;
            struct Edge* ECurr = current->Elist;
            while (ECurr != NULL)
            {
                cout << "Edge: " << (ECurr->ToVertex->data) << endl;
                ECurr = ECurr->next;
            }

            current = current->Next;
        }
    }
}
//=======================================delete functions===================================
void DeleteEdge(string c) {
    string edgeChar;
    Vertex* main = Cstart; // points the vertex 
    while (main != NULL) { // runs till the main pointer is null
        if (main->data == c)
        {
            Edge* sub = main->Elist; // points edges
            cout << "Enter the edge you want to delete: ";
            cin >> edgeChar;
            if (sub == NULL) // checks for vertex with no edges
            {
                cout << "there are no such edges in this vertex\n";
                return;
            }

            if (sub->ToVertex->data == edgeChar) // checks for first edge
            {
                main->Elist = sub->next;
                free(sub);
                return;
            }

            Edge* Sprev = main->Elist; // points to 1 edge previous to main sub pointer
            sub = sub->next;

            while (sub != NULL)// for edges in between
            {
                if (sub->ToVertex->data == edgeChar) {
                    Sprev->next = sub->next;
                    free(sub);
                    cout << "Edge deleted\n";
                    return;
                }
                sub = sub->next;
                Sprev = Sprev->next;

            }
        }
        main = main->Next;
    }
    if (main == NULL)
    {
        cout << "Given vertex dosent exist...\n";
        return;
    }

}

//========================================path===============================================


int Hashfn(char b) {
    int a = (int)b - 97;
    return(a);
}

void Bfs(string b) {
    int* arr = new int[26];
    for (int i = 0; arr[i]; i++) {
        arr[i] = 0;
    }
    queue <Vertex*> q1;
    // root is pushed
    Vertex* main = Cstart;
    q1.push(main);
    int index = main->index;
    // root is visited
    arr[index] = 1;
    // runs till queue is not empty
    while (!q1.empty()) {
        Vertex* output = q1.front();
        q1.pop();
        cout << "|" << output->data << "|" << " -> ";
        if (output->Elist == NULL) {
            continue;
        }
        Edge* sub = output->Elist;

        while (sub != NULL) {
            if (sub->ToVertex->data == b) {
                cout << "-> |" << sub->ToVertex->data << "|" << " path exist" << endl;
                int ind = sub->ToVertex->index;
                arr[ind] = 1;
                for (int i = 0; i < 26; i++) {
                    cout << arr[i] << "\t";
                }
                cout << endl;
                return;
            }
            int ind = sub->ToVertex->index;
            if (arr[ind] == 0) {
                q1.push(sub->ToVertex);
                cout << "|" << sub->ToVertex->data << "|" << "  ";
                arr[ind] = 1;
            }

            sub = sub->next;
        }
        cout << endl;
    }
    cout << "path not exist" << endl;
}


//special bfs that takes the starting point also
void Bfs2(string source, string b) {
    int* arr = new int[26];
    for (int i = 0; arr[i]; i++) {
        arr[i] = 0;
    }

    Vertex* main = Cstart;
    while (main != NULL) {
        if (main->data == source) {
            break;
        }
        main = main->Next;
    }

    queue <Vertex*> q1;
    // root is pushed
    q1.push(main);
    // root is visited
    arr[main->index] = 1;
    // runs till queue is not empty
    while (!q1.empty()) {
        Vertex* output = q1.front();
        q1.pop();
        cout << "p: |" << output->data << "|" << " -> ";
        if (output->Elist == NULL) {
            continue;
        }
        Edge* sub = output->Elist;

        while (sub != NULL) {
            if (sub->ToVertex->data == b) {
                cout << "-> |" << sub->ToVertex->data << "|" << " path exist" << endl;
                int ind = sub->ToVertex->index;
                arr[ind] = 1;
                for (int i = 0; i < 26; i++) {
                    cout << arr[i] << "\t";
                }
                cout << endl;
                return;
            }
            int ind = sub->ToVertex->index;
            if (arr[ind] == 0) {
                q1.push(sub->ToVertex);
                cout << "c: |" << sub->ToVertex->data << "|" << "  ";
                arr[ind] = 1;
            }

            sub = sub->next;
        }
        cout << endl;
    }
    cout << "path not exist" << endl;
}


int cdfs = 0;// it  gets 1 when path found (checkdepthfirstsearch)




void maze(int row, int col) {
    // creating dynamic 2d array
    char** arr = new char* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new char[col];
    }

    // initializing values
    string ver;
    string StartPosi;
    string EndPosi;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // makes a vertex eg 0,0
            ver = "";
            ver = intToString(i) + "," + intToString(j);
            InsertVertex(ver);
            // initialize array val 
            char val;
            cout << "Enter value at " << i << "," << j << ": ";
            cin >> val;
            // getting the starting position where u is present
            if (val == 'u')
            {
                StartPosi = intToString(i) + "," + intToString(j);
            }
            if (val == 'h')
            {
                EndPosi = intToString(i) + "," + intToString(j);
            }
            arr[i][j] = val;
        }
    }

    string ver1;
    string ver2;
    for (int i = 0; i < row; i++) //starting from the given posi
    {
        for (int j = 0; j < col; j++)
        {
            cout << "ok\n";
            if (arr[i][j] == 'x') //if x then skip
            {
                continue;
            }
            if (j + 1 < col)// checking right
            {
                if (arr[i][j + 1] == '-' || arr[i][j + 1] == 'u' || arr[i][j + 1] == 'h') {
                    ver1 = "";
                    ver1 = intToString(i) + "," + intToString(j);// source
                    ver2 = "";
                    ver2 = intToString(i) + "," + intToString(j + 1);// destination
                    InsertEdge(ver1, ver2);
                }
            }
            if (i + 1 < row)// checking down
            {
                if (arr[i + 1][j] == '-' || arr[i + 1][j] == 'u' || arr[i + 1][j] == 'h')
                {
                    ver1 = "";
                    ver1 = intToString(i) + "," + intToString(j);// source
                    ver2 = "";
                    ver2 = intToString(i + 1) + "," + intToString(j);// destination
                    InsertEdge(ver1, ver2);
                }
            }
            if ((j - 1 >= 0))// checking left
            {
                if (arr[i][j - 1] == '-' || arr[i][j - 1] == 'u' || arr[i][j - 1] == 'h')
                {
                    ver1 = "";
                    ver1 = intToString(i) + "," + intToString(j);// source
                    ver2 = "";
                    ver2 = intToString(i) + "," + intToString(j - 1);// destination
                    InsertEdge(ver1, ver2);
                }

            }
            if ((i - 1 >= 0))// checking up
            {
                if (arr[i - 1][j] == '-' || arr[i - 1][j] == 'u' || arr[i - 1][j] == 'h')
                {
                    ver1 = "";
                    ver1 = intToString(i) + "," + intToString(j);
                    ver2 = "";
                    ver2 = intToString(i - 1) + "," + intToString(j);
                    InsertEdge(ver1, ver2);
                }
            }
        }
    }
    Bfs2(StartPosi,EndPosi);
    // printing bad kay use kay liay
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a = 0;
    string c;
    while (a != 10) {
        cout << "press 1 for inserting a vertex, 2 for inserting a Edge, 3 for printing course list, 4 delete edge, 5 delete vertex, 6 find path, 7 dfs , 8 print edge, 9 for exit" << endl;
        cin >> a;
        if (a == 1) {
            cout << "Enter your vertex: ";
            cin >> c;
            InsertVertex(c);
        }
        if (a == 2) {
            cout << "Enter on which vertex you want to make a connection: ";
            cin >> c;
            //InsertEdge(c);
        }
        if (a == 3) {
            printgraph();
        }
        if (a == 4) {
            cout << "Enter the vertex where you want to delete an edge: ";
            cin >> c;
            DeleteEdge(c);
        }
        if (a == 5) {
            cout << "Enter the vertex you want to delete: ";
            cin >> c;
//            DeleteVertex(c);
        }
        if (a == 6)
        {
            int n;
            int m;
            cout << "Enter rows: ";
            cin >> n;
            cout << "Enter col: ";
            cin >> m;
            maze(n, m);

        }
       
        if (a == 7) {
            cout << "Enter the vertex of which you want the path of: ";
            cin >> c;
            Bfs(c);
        }
        if (a == 8) {
            cout << "Exiting";
            break;
        }

    }
}
