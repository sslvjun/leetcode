#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define MIN(a, b)   ((a) > (b) ? (b) : (a))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *numsA, *numsB;
    int m, n, iMax, iMin, halfLen, i, j;
    
    if (nums1Size > nums2Size) {    // to ensure numsA Size <= numsB Size
        numsA = nums2;
        numsB = nums1;
        m = nums2Size;
        n = nums1Size;
    }
    else {
        numsA = nums1;
        numsB = nums2;
        m = nums1Size;
        n = nums2Size;
    }
    
    iMin = 0;
    iMax = m;
    halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        i = (iMin + iMax) / 2;
        j = halfLen - i;
        if (i < iMax && numsB[j - 1] > numsA[i]) {
            iMin = i + 1;   // i is too small
        }
        else if (i > iMin && numsA[i - 1] > numsB[j]) {
            iMax = i - 1;   // i is too big
        }
        else {  // i is perfect
            int maxLeft = 0;
            int minRight = 0;
            
            if (i == 0) {
                maxLeft = numsB[j-1];
            }
            else if (j == 0) { 
                maxLeft = numsA[i-1];
            }
            else {
                maxLeft = MAX(numsA[i-1], numsB[j-1]);
            }
                
            if ( (m + n) % 2 == 1 ) { 
                return maxLeft; 
            }

                
            if (i == m) {
                minRight = numsB[j];
            }
            else if (j == n) {
                minRight = numsA[i];
            }
            else { 
                minRight = MIN(numsB[j], numsA[i]);
            }

            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0;
}
