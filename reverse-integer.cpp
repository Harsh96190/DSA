class Solution {
public:
    int reverse(int n) {
      int reversed_number = 0;
      while (n!=0)
      { int h= n%10;
     
      if (reversed_number>INT_MAX/10 || reversed_number<INT_MIN/10)
      {return 0;
      break;}
       reversed_number =reversed_number * 10 + h;
      n=n/10;}
      return reversed_number; 
    }

};