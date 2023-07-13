#include<iostream>
#include<string.h>
using namespace std;
class node
{
public:
    char data;
    node *next;
};

class node_s
{
public:
    float data;
    node_s *next;
};

node *char_top = NULL;
node_s *start=NULL;

node *create_node(node* ptr,char data)
{
node* new_node;
new_node=(node*)malloc(sizeof(node));
new_node->data=data;
new_node->next=ptr;
return new_node;
}

void push(char data)
{
    char_top = create_node(char_top, data);
}

char pop()
{
    char val = char_top->data;
    node *ptr = char_top;
    if(char_top->next)
    {
        char_top=char_top->next;
    }
    else
    {
        char_top=NULL;
    }
    free(ptr);
    return val;
}
//===================================

node_s *create_node2(node_s *ptr, float data)
{
    node_s *new_node;
    new_node = (node_s *)malloc(sizeof(node_s));
    new_node->data = data;
    new_node->next = ptr;
    return new_node;
}
void push2(float data)
{
    start = create_node2(start, data);
}
float pop2()
{
    float val = start->data;
    node_s *ptr = start;
    if (start->next)
    {
        start = start->next;
    }
    else
    {
        start = NULL;
    }
    free(ptr);
    return val;
}

//===================================

void view(node *ptr)
{
    if (ptr)
    {
        cout << ptr->data << " ";
        view(ptr->next);
    }
}

int priority(char s)
{
    if (s == '+' || s == '-')
    {
        return 0;
    }
    if (s == '*' || s == '/'|| s == '%')
    {
        return 1;
    }
    if(s=='^')
    {
        return 2;
    }
    return -1;
}

string infToPost(string s)
{
    string stack, postfix;
    char c;
    s = '(' + s + ')';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/'&& s[i] != '%'&& s[i] != '^')
        {
            postfix = postfix + s[i];
            if(s[i+1] == '(' || s[i+1] == ')' || s[i+1] == '+' || s[i+1] == '-' || s[i+1] == '*' || s[i+1] == '/'|| s[i+1] == '%'|| s[i+1] == '^')
            {
                postfix = postfix + " ";
            }
        }
        else
        {
            if (s[i] == '(')
            {
                if(s[i+1] == '+' || s[i+1] == '-')
                {
                    postfix = postfix + "0 ";
                }
                push(s[i]);
            }
            else if (s[i] == ')')
            {
                do
                {
                    c = pop();
                    if (c != '(')
                    {
                        postfix = postfix + c+" ";
                    }
                } while (c != '(');
            }
            else
            {
                if (priority(char_top->data) == priority(s[i]))
                {
                    if(s[i]=='^')
                    {
                        push(s[i]);
                    }
                    else{c = pop();
                    while (priority(c) == priority(s[i]))
                    {
                        if (c != '(')
                        {
                            postfix = postfix + c+" ";
                        }
                        c = pop();
                    }
                    push(c);
                    push(s[i]);}
                    
                }
                else if (priority(char_top->data) < priority(s[i]))
                {
                    push(s[i]);
                }
                else if (priority(char_top->data) >= priority(s[i]))
                {

                    do
                    {
                        c = pop();
                        if (c != '(')
                        {
                            postfix = postfix + c+" ";
                        }
                    } while (c != '(');
                    push('(');
                    push(s[i]);
                }
            }
        }
    }
    return (" "+postfix);
}

float cal(string s)
{
int i=0,val;
string temp="";
s=s+'E';
while(s[i]==' '&& s[i]!='E')
{
if(s[i+1] == '+' || s[i+1] == '-' || s[i+1] == '*' || s[i+1] == '/'|| s[i+1] == '%'|| s[i+1] == '^')
{
float x,y,z;
y=pop2();
x=pop2();
switch (s[i+1])
{
case '^':
    z=1;
    if(y==0)
    {
        z=1;
    }
    else
    {
        for(int i=0;i<y;i++)
        {
            z=z*x;
        }
    }
    break;
case '*':
    z=x*y;
    break;
case '/':
    z=x/y;
    break;
case '%':
    z=(int)x%(int)y;
    break;
case '+':
    z=x+y;
    break;
case '-':
    z=x-y;
    break;
default:
    break;
}
push2(z);
i++;
}
else if(s[i+1]!='E'){
while(s[i+1]!=' ')
{
temp=temp+s[i+1];
i++;
}
val=stof(temp);
push2(val);
temp="";
}
i++;
}
return pop2();
}

int main()
{
    string s;
    cout << "Enter eqation:";
    cin >> s;
    s=infToPost(s);
    cout<<cal(s);
}
