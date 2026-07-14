class Solution {
public:
    int getSum(int a, int b) {
    uint32_t carry= a & b;
    int sum= a ^ b; 
    int actual_carry= carry << 1;
    while(carry!=0){
        carry=sum & actual_carry;
        sum=sum ^ actual_carry;
        actual_carry=carry << 1;
    }
return sum;

    }
};
