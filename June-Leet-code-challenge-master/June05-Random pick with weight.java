class Solution {
    private int[] presum;
    private int n;
    private Random rand;

    public Solution(int[] w) {
        n = w.length;
        presum = new int[n];
        rand = new Random();
        presum[0] = w[0];
        for (int i = 1; i < n; i++) presum[i] = presum[i - 1] + w[i];
    }
    public int pickIndex() {
        int r = rand.nextInt(presum[n - 1]) + 1;
        int i = Arrays.binarySearch(presum, r);
        if (i < 0) i = -(i + 1);
        return i;
    }
}
