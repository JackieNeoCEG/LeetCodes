class Solution {
    public String intToRoman(int num) {
        TreeMap<Integer, String> numeralMap = new TreeMap<>((a, b) -> b - a);
        numeralMap.put(1000, "M"); numeralMap.put(900, "CM");
        numeralMap.put(500, "D"); numeralMap.put(400, "CD");
        numeralMap.put(100, "C"); numeralMap.put(90, "XC");
        numeralMap.put(50, "L"); numeralMap.put(40, "XL");
        numeralMap.put(10, "X"); numeralMap.put(9, "IX");
        numeralMap.put(5, "V"); numeralMap.put(4, "IV"); numeralMap.put(1, "I");

        StringBuilder result = new StringBuilder();//Stringbuilder is used for concatenating
        
        for (int value : numeralMap.keySet()) {
            while (num >= value) {
                result.append(numeralMap.get(value));//concat
                num -= value;
            }
        }

        return result.toString();
    }
    
}