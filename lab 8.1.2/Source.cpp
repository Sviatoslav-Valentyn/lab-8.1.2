#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* str, const char a, const char b, int i)
{
    if ((a == str[i] && b == str[i + 1]) ||
        (b == str[i] && a == str[i + 1]))
        return 1;
    if (str[i] != '\0' && str[i + 1] != '\0')
        return Include(str, a, b, i + 1);
    else
        return 0;
}
char* Replace(char* R, const char* str, char* s, int i)
{
    if (str[i] != '\0' && str[i + 1] != '\0')
    {
        if ((str[i] == 'S' && str[i + 1] == 'Q') ||
            (str[i] == 'Q' && str[i + 1] == 'S'))
        {
            strcat(s, "***");
            return Replace(R, str, s + 3, i + 2);
        }
        else
        {
            *s++ = str[i++];
            *s = '\0';
            return Replace(R, str, s, i);
        }
    }
    else
    {
        *s++ = str[i++];
        *s++ = str[i++];
        *s = '\0';
        return R;
    }
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    char a = 'Q';
    char b = 'S';
    if (Include(str, a, b, 0))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    char* R1 = new char[151];
    R1[0] = '\0';
    char* R2;
    R2 = Replace(R1, str, R1, 0);
    cout << "Modified string (result): " << R2 << endl;
    return 0;
}