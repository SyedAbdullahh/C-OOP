#include <iostream>
#include<string>
using namespace std;

class Garment {
    char name[20];
public:
    Garment();
    ~Garment();
    virtual string getname();
    virtual int calculatePrice() = 0;
    virtual int getcollarSize();
    virtual void setcollarSize(int c);
    virtual int getwaistSize();
    virtual void setwaistSize(int w);
};

Garment::Garment() {
    cout << "\n Ctr Called";
}

Garment::~Garment() {
    cout << "\n Dtr Called";
    for (int i = 0; i < 20; i++) {
        name[i] = NULL;
    }
}

string Garment::getname() {
    return name;
}



int Garment::getcollarSize() {
    return 0;
}

void Garment::setcollarSize(int c) {
    // Do nothing in the base class
}

int Garment::getwaistSize() {
    return 0;
}

void Garment::setwaistSize(int w) {
    // Do nothing in the base class
}

class Upper : public Garment {
protected:
    int collarSize;
public:
    int getcollarSize() override;
    void setcollarSize(int c) override;
};

int Upper::getcollarSize() {
    return collarSize;
}

void Upper::setcollarSize(int c) {
    collarSize = c;
}

class Lower : public Garment {
protected:
    int waistSize;
public:
    int getwaistSize() override;
    void setwaistSize(int w) override;
};

int Lower::getwaistSize() {
    return waistSize;
}

void Lower::setwaistSize(int w) {
    waistSize = w;
}

class Shirt : public Upper {
public:
    Shirt();
    ~Shirt();
    int calculatePrice() override;
    virtual string getname() ;
};

Shirt::Shirt() {
    cout << "\n Shirt Created";
}

Shirt::~Shirt() {
    cout << "\n Shirt Destroyed";
}

int Shirt::calculatePrice() {
    int pr = ((collarSize-1) * 20) + 10;
    return pr;
}

string Shirt::getname() {
    return "Shirt";
}

class Pajama : public Lower {
public:
    Pajama();
    ~Pajama();
    int calculatePrice() ;
    virtual string getname() ;
};

Pajama::Pajama() {
    cout << "\n Pajama Added";
}

Pajama::~Pajama() {
    cout << "\n Pajama Destroyed";
}

int Pajama::calculatePrice() {
    int pr = ((waistSize-2) * 15) + 50;
    return pr;
}

string Pajama::getname() {
    return "Pajama";
}

class Trouser : public Lower {
public:
    Trouser();
    ~Trouser();
    int calculatePrice() override;
   virtual string getname() ;
};

Trouser::Trouser() {
    cout << "\n Trouser Added";
}

Trouser::~Trouser() {
    cout << "\n Trouser deleted";
}

int Trouser::calculatePrice() {
    int pr = ((waistSize-3) * 15) + 50;
    return pr;
}

string Trouser::getname() {
    return "Trouser";
}

void Show_main() {
    cout << "\n------------------Welcome To Clothing Store----------------";
    cout << "\n1. Add Product to Cart";
    cout << "\n2. Remove Product from Cart";
    cout << "\n3. Make Payment";
    cout << "\n0.Exit";
    cout << "\n Choose Option(0-3):";
   
}

int Show_prod() {
    int p_ans;
    system("cls");
    cout << "\n1.Shirt";
    cout << "\n2.Pajama";
    cout << "\n3.Trouser";
    cout << "\n0.Exit";
    cout << "\n Choose Option(0-3):";
    cin >> p_ans;
    while (cin.fail() || (p_ans < 0) || (p_ans > 3)) {
        cout << "\n Invalid Input...";
        cin.clear();
        cin.ignore(256,'\n');
        cout << "\n Choose Option(0-3):";
        cin >> p_ans;
    }
    return p_ans;
}

int main() {
    const int max = 10;
    Garment* g[max];
    int curr = 0;
    bool flag = true;
    while (flag) {
        Show_main();
        static int ans;
        cin >> ans;
        while (cin.fail() || (ans < 0) || (ans > 3)) {
            cout << "\n Invalid Input...";
            cin.clear();
            cin.ignore( 256,'\n');
            cout << "\n Choose Option(0-3):";
            cin >> ans;
        }
        switch (ans) {
        case 1: {
            if (curr < 10)
            {
                int p_ans = Show_prod();
                if (p_ans == 1) {
                    int col_s;
                    g[curr] = new Shirt();
                    cout << "\n Enter Collar Size for Shirt:";
                    cin >> col_s;
                    while (cin.fail() || (col_s <= 0)) {
                        cout << "\n Invalid Input...";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout << "\n Enter Collar Size for Shirt:";
                        cin >> col_s;
                    }
                    g[curr]->setcollarSize(col_s);
                    curr++;
                    system("cls");
                    continue;
                }
                if (p_ans == 2) {
                    int waist;
                    g[curr] = new Pajama();
                    cout << "\n Enter Waist for Pajama:";
                    cin >> waist;
                    while (cin.fail() || (waist <= 0)) {
                        cout << "\n Invalid Input...";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout << "\n Enter Waist for Pajama:";
                        cin >> waist;
                    }
                    g[curr]->setwaistSize(waist);
                    curr++;
                    system("cls");
                    continue;
                }
                if (p_ans == 3) {
                    int waist;
                    g[curr] = new Trouser();
                    cout << "\n Enter Waist for Trouser:";
                    cin >> waist;
                    while (cin.fail() || (waist <= 0)) {
                        cout << "\n Invalid Input...";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout << "\n Enter Waist for Trouser:";
                        cin >> waist;
                    }
                    g[curr]->setwaistSize(waist);
                    curr++;
                    system("cls");
                    continue;
                }
                if (p_ans == 0)
                {
                    return 0;
                }
            }
            else
            {
                system("cls");
                cout << "\nMaximum capacity of adding Products has been Reached. Remove Some to add more";
                system("pause");
                system("cls");
            }
            break;
        }
        case 2: {
            system("cls");
            int ind;
            for (int i = 0; i < curr; i++) {
                cout << endl << i + 1 << "." + g[i]->getname();
            }
            cout << "\n Enter which one do you wanna Remove(1-" << curr << "):";
            cin >> ind;
            while (cin.fail() || (ind <= 0) || (ind > curr)) {
                cout << "\n Invalid Input...";
                cin.clear();
                cin.ignore( 256,'\n');
                cout << "\n Enter which one do you wanna Remove(1-" << curr << "):";
                cin >> ind;
            }
            ind--;
            delete g[ind];
            for (int i = ind; i < curr; i++) {
                g[i] = g[i + 1];
            }
            curr--;
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            int bill = 0;
            cout << "\n-------------Receipt----------------------";
            for (int i = 0; i < curr; i++) {
                cout << "\n" << i + 1 << "." << g[i]->getname() << "\t" << g[i]->calculatePrice();
                bill += g[i]->calculatePrice();
            }
            cout << "\nBill:" << bill << "PKR" << endl;

            cout << "\nThank you for shopping at our Store\n";

            system("pause");
            break;
        }
        case 0: {
            flag = false;
            break;
        }
        }
    }

    return 0;
}
