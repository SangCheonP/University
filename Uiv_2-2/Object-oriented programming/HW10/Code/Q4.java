import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class Q4 {
	public static void main(String[] args) {
		String[] data = { "A", "K", "A", "K", "D", "A", "K", "K", "K", "Z", "D" };
		HashMap<String, Integer> map = new HashMap<>();
		
		for(int i = 0; i < data.length; i++) {
			if(map.containsKey(data[i])) {
				int v = map.get(data[i]);
				map.put(data[i], v+1);
			}else {
				map.put(data[i], 1);
			}
		}
		
		List<String> ks = new ArrayList<> (map.keySet());
		Collections.sort(ks);
		Iterator<String> itr = ks.iterator();
		while(itr.hasNext()) {
			String key = itr.next();
			System.out.println(key + " : " + map.get(key));
		}
	}
}
