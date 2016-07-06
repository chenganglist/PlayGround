public class hexStringToDecimal {
  public static void main(String[] args) {
    String s = "0x405E";
    int b = Integer.parseInt( s.replaceAll("^0[x|X]",""), 16);
    System.out.println(b);
  }
}