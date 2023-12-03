/********************************************************
 *This code orginally Written By
 *Author: Dipankar Kumar Roy
 *If you want to use this code, please mention Authors name.
 *********************************************************/
#ifndef MSOLVE_HPP
#define MSOLVE_HPP
class _Dip_
{
public:
    char data;
    _Dip_ *next;
};

class _Dip__s
{
public:
    double data;
    _Dip__s *next;
};

class _Dip_Node
{
public:
    std::string data;
    _Dip_Node *next;

    _Dip_Node(const std::string &value) : data(value), next(nullptr) {}
};

class _Dip_ll
{
private:
    _Dip_Node *head;

public:
    _Dip_ll() : head(nullptr) {}

    void insert(const std::string &value)
    {
        _Dip_Node *newNode = new _Dip_Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            _Dip_Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    std::string search(const std::string &key)
    {
        _Dip_Node *current = head;
        while (current)
        {
            size_t pos = current->data.find(key + ":");
            if (pos == 0)
            {
                size_t colonPos = current->data.find(':');
                if (colonPos != std::string::npos)
                {
                    return current->data.substr(colonPos + 1);
                }
            }
            current = current->next;
        }
        return "";
    }

    ~_Dip_ll()
    {
        while (head)
        {
            _Dip_Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

_Dip_ *char_top = __null;
_Dip__s *start = __null;

_Dip_ *create__Dip_(_Dip_ *ptr, char data)
{
    _Dip_ *new__Dip_;
    new__Dip_ = (_Dip_ *)malloc(sizeof(_Dip_));
    new__Dip_->data = data;
    new__Dip_->next = ptr;
    return new__Dip_;
}

void _Dip_push_(char data)
{
    char_top = create__Dip_(char_top, data);
}

char _Dip_pop_()
{
    char val = char_top->data;
    _Dip_ *ptr = char_top;
    if (char_top->next)
    {
        char_top = char_top->next;
    }
    else
    {
        char_top = __null;
    }
    free(ptr);
    return val;
}

_Dip__s *create__Dip_2(_Dip__s *ptr, double data)
{
    _Dip__s *new__Dip_;
    new__Dip_ = (_Dip__s *)malloc(sizeof(_Dip__s));
    new__Dip_->data = data;
    new__Dip_->next = ptr;
    return new__Dip_;
}
void _Dip_push_2(double data)
{
    start = create__Dip_2(start, data);
}
double _Dip_pop_2()
{
    double val = start->data;
    _Dip__s *ptr = start;
    if (start->next)
    {
        start = start->next;
    }
    else
    {
        start = __null;
    }
    free(ptr);
    return val;
}

class _Dip_queue_
{
public:
    double data;
    _Dip_queue_ *next;

    _Dip_queue_(double val) : data(val), next(nullptr) {}
};

class _queue_
{
private:
    _Dip_queue_ *front;
    _Dip_queue_ *rear;

public:
    _queue_() : front(nullptr), rear(nullptr) {}

    void _Dip_push_(double value)
    {
        _Dip_queue_ *new_Dip_queue_ = new _Dip_queue_(value);
        if (isEmpty())
        {
            front = rear = new_Dip_queue_;
        }
        else
        {
            rear->next = new_Dip_queue_;
            rear = new_Dip_queue_;
        }
    }

    double _Dip_pop_()
    {
        if (isEmpty())
        {
            std::cerr << "Missing value." << std::endl;
            return -1;
        }
        else
        {
            double _Dip_pop_pedValue = front->data;
            _Dip_queue_ *temp = front;
            front = front->next;
            delete temp;
            return _Dip_pop_pedValue;
        }
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }
};

int _Dip_pri_(char s)
{
    if (s == '+' || s == '-')
    {
        return 0;
    }
    if (s == '*' || s == '/' || s == '%')
    {
        return 1;
    }
    if (s == '^')
    {
        return 2;
    }
    return -1;
}

std::string _Dip_InfTPo_(std::string s)
{
    std::string stack, postfix;
    char c;
    s = '(' + s + ')';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '%' && s[i] != '^')
        {
            postfix = postfix + s[i];
            if (s[i + 1] == '(' || s[i + 1] == ')' || s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '%' || s[i + 1] == '^')
            {
                postfix = postfix + " ";
            }
        }
        else
        {
            if (s[i] == '(')
            {
                if (s[i + 1] == '+' || s[i + 1] == '-')
                {
                    postfix = postfix + "0 ";
                }
                _Dip_push_(s[i]);
            }
            else if (s[i] == ')')
            {
                do
                {
                    c = _Dip_pop_();
                    if (c != '(')
                    {
                        postfix = postfix + c + " ";
                    }
                } while (c != '(');
            }
            else
            {
                if (_Dip_pri_(char_top->data) == _Dip_pri_(s[i]))
                {
                    if (s[i] == '^')
                    {
                        _Dip_push_(s[i]);
                    }
                    else
                    {
                        c = _Dip_pop_();
                        while (_Dip_pri_(c) == _Dip_pri_(s[i]))
                        {
                            if (c != '(')
                            {
                                postfix = postfix + c + " ";
                            }
                            c = _Dip_pop_();
                        }
                        _Dip_push_(c);
                        _Dip_push_(s[i]);
                    }
                }
                else if (_Dip_pri_(char_top->data) < _Dip_pri_(s[i]))
                {
                    _Dip_push_(s[i]);
                }
                else if (_Dip_pri_(char_top->data) >= _Dip_pri_(s[i]))
                {

                    do
                    {
                        c = _Dip_pop_();
                        if (c != '(')
                        {
                            postfix = postfix + c + " ";
                        }
                    } while (c != '(');
                    _Dip_push_('(');
                    _Dip_push_(s[i]);
                }
            }
        }
    }
    return (" " + postfix);
}

double _Dip_cal_(std::string s)
{
    int i = 0;
    double val;
    std::string temp = "";
    s = s + 'E';
    while (s[i] == ' ' && s[i] != 'E')
    {
        if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '%' || s[i + 1] == '^')
        {
            double x, y, z;
            y = _Dip_pop_2();
            x = _Dip_pop_2();
            switch (s[i + 1])
            {
            case '^':
                z = 1;
                if (y == 0)
                {
                    z = 1;
                }
                else if (y < 0)
                {
                    y = y * (-1);
                    for (int i = 0; i < y; i++)
                    {
                        z = z * x;
                    }
                    z = 1 / z;
                }
                else
                {
                    for (int i = 0; i < y; i++)
                    {
                        z = z * x;
                    }
                }
                break;
            case '*':
                z = x * y;
                break;
            case '/':
                z = x / y;
                break;
            case '%':
                z = (int)x % (int)y;
                break;
            case '+':
                z = x + y;
                break;
            case '-':
                z = x - y;
                break;
            default:
                break;
            }
            _Dip_push_2(z);
            i++;
        }
        else if (s[i + 1] != 'E')
        {
            while (s[i + 1] != ' ')
            {
                temp = temp + s[i + 1];
                i++;
            }
            val = stod(temp);
            _Dip_push_2(val);
            temp = "";
        }
        i++;
    }
    return _Dip_pop_2();
}

template <typename... Args>
std::string _Dip_conv_(const std::string &s, Args... args)
{
    _Dip_ll list;
    int k = 0, id = 0;
    std::string ts;
    _queue_ my_queue_;
    (my_queue_._Dip_push_(args), ...);
    while (s[k] != '\0')
    {
        while (s[k] == ' ')
        {
            k++;
        }
        if (isalpha(s[k]) || s[k] == '_')
        {
            std::string temp = "";
            std::string temp1 = "";
            while (isalpha(s[k]) || s[k] == '_' || s[k] == ' ' || isdigit(s[k]))
            {
                if (s[k] != ' ')
                {
                    temp = temp + s[k];
                }

                k++;
            }
            temp1 = list.search(temp);
            if (temp1 == "")
            {
                double x = my_queue_._Dip_pop_();
                if (x < 0)
                {
                    ts = ts + "(0" + std::to_string(x) + ")";
                    list.insert(temp + ':' + "(0" + std::to_string(x) + ")");
                }
                else
                {
                    ts = ts + std::to_string(x);
                    list.insert(temp + ':' + std::to_string(x));
                }
            }
            else
            {
                ts = ts + temp1;
            }
        }
        else if (!isalnum(s[k]) || isdigit(s[k]))
        {
            ts = ts + s[k];
            k++;
        }
        else
        {
            k++;
        }
    }

    return ts;
}

double Msolve(std::string s)
{
    int k = 0;
    std::string ts;
    while (s[k] != '\0')
    {
        if (s[k] != ' ')
        {
            ts = ts + s[k];
        }

        k++;
    }
    return _Dip_cal_(_Dip_InfTPo_(ts));
}

template <typename... Args>
double Msolve(std::string s, Args... args)
{
    s = _Dip_conv_(s, args...);
    return _Dip_cal_(_Dip_InfTPo_(s));
}

#endif
