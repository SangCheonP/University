import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Q2 {
	public static void main(String[] args) {
		List<Person> list = new ArrayList<>();
		list.add(new Person("Yoon", 23));
		list.add(new Person("Hong", 53));
		list.add(new Person("Kim", 37));
		list.add(new Person("Park", 67));
		list.add(new Person("Lee", 15));
		
		Collections.sort(list, (s1,s2) -> s1.age - s2.age);
		System.out.println("*** 나이순 정렬 ***");
		for(Person s : list) {
			System.out.println(s.toString());
		}
		System.out.println();
	
		Collections.sort(list, (s1, s2) -> s1.name.compareTo(s2.name));
		System.out.println("*** 이름순 정렬 ***");
		for(Person s : list) {
			System.out.println(s.toString());
		}
		
	}
}

class Person {
	String name;
	int age;

	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String toString() {
		return name + " : " + age;
	}
}
