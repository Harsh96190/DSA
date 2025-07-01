class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int a = nums1.size(),b = nums2.size();
     int c = a + b;
     int index2 = c/2, index1 = (c/2 -1);
     int count = -1;
     int i=0,j=0;
     int med1=0,med2=0;

     if(a==0 && b==0) return 0;

     while (i<a && j<b)
     {
        if (nums1[i]<nums2[j]){
            count++; 
            if (count == index1) med1 = nums1[i];
            if (count == index2) {med2 = nums1[i];break;}
            i++;}
        else{
            count++;
            if (count == index1) med1 = nums2[j];
            if (count == index2) {med2 = nums2[j];break;}
            j++;}
     }  

    while (i<a){
        count++; 
        if (count == index1) med1 = nums1[i];
        if (count == index2){ med2 = nums1[i];break;}
        i++;   
        }

    while (j<b){
        count++;
        if (count == index1) med1 = nums2[j];
        if (count == index2) {med2 = nums2[j];break;}
        j++;
        }
    if(c%2!=0) return med2;
    else return (med1+med2)/2.0;

    }
};