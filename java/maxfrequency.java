/*  Q3. Maximum Frequency After Subarray Operation
        Medium
5 pt.
You are given an array nums of length n. You are also given an integer k.

You perform the following operation on nums once:

Select a
subarray
nums[i..j] where 0 <= i <= j <= n - 1.
Select an integer x and add x to all the elements in nums[i..j].
Find the maximum frequency of the value k after the operation.

*/


public class maxfrequency {
    public static int maxFrequency(int[] nums, int k) {
        int maxFrequency = 0;
        int n=nums.length;

        for (int i =0; i<n; i++){
            for(int j=i ; j<n; j++) {
                int count =0;
                int required = k - nums[i];
                for(int x=i;x<=j; x++){
                    if(nums[x] +required == k){
                        count++;
                    }
                }
                maxFrequency = Math.max(maxFrequency,count);
            }
        }
        return maxFrequency;
    }
    public static void main(String[] args){
        int[] nums = {3,3,3,3,6};
//        int[] nums = {10,4,4,4,4,4,5,3};
        int k=10;
        System.out.println(maxFrequency(nums,k));
    }
}