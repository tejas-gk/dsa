#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
//anagram
void anagram(std::string str1, std::string str2)
{
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if (str1 == str2)
        std::cout << "Anagrams" << std::endl;
    else
        std::cout << "Not anagrams" << std::endl;
}
//permutation
void permutation(std::string str1, std::string str2)
{
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if (str1 == str2)
        std::cout << "Permutations" << std::endl;
    else
        std::cout << "Not permutations" << std::endl;
}
//palindrome
void palindrome(std::string str)
{
    std::string rev = str;
    std::reverse(rev.begin(), rev.end());
    if (str == rev)
        std::cout << "Palindrome" << std::endl;
    else
        std::cout << "Not palindrome" << std::endl;
}
//anagram and permutation
void anagram_permutation(std::string str1, std::string str2)
{
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if (str1 == str2)
    {
        std::cout << "Anagrams and Permutations" << std::endl;
    }
    else
    {
        std::cout << "Not anagrams and permutations" << std::endl;
    }
}
int main(){
    std::string str1 = "racecar";
    std::string str2 = "racecar";
    anagram(str1, str2);
    permutation(str1, str2);
    palindrome(str1);
    anagram_permutation(str1, str2);
    return 0;

}