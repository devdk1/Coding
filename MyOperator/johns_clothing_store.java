import java.util.*;
class johns_clothing_store 
{

	public static void number_of_socks(int arg1, int[] arg2) 
	{
		HashMap<Integer, Integer> map = new HashMap<>();
		
		for(int i = 0; i < arg1; i++) {
            Integer cnt = map.get(arg2[i]);
			map.put(arg2[i], (cnt == null) ? 1 : cnt + 1);
		}
		
		int pair = 0;
		Iterator mapIterator = map.entrySet().iterator(); 
		while(mapIterator.hasNext()) {
            Map.Entry mapElement = (Map.Entry)mapIterator.next(); 
            int val = (int)mapElement.getValue();
            if(val >= 2) {
            	pair += val / 2;
            }
		}
		System.out.println(pair);
	}

	public static void main(String arg[]) 
	{
		Scanner s = new Scanner(System.in);
		int arg1;
		arg1 = s.nextInt();
		int arg2[] = new int[arg1];
		for (int i = 0; i < arg1; i++) {
			arg2[i] = s.nextInt();
		}
        number_of_socks(arg1, arg2);
	}

}