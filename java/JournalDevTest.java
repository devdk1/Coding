public class JournalDevTest {

	private String name;
	private int id;

	//no-args constructor
	public JournalDevTest() {
		this.name = "Default Name";
	}
	//one parameter constructor
	public JournalDevTest(String n) {
		this.name = n;
	}
	//two parameter constructor
	public JournalDevTest(String n, int i) {
		this.name = n;
		this.id = i;
	}

	public String getName() {
		return name;
	}

	public int getId() {
		return id;
	}

	@Override
	public String toString() {
		return "ID="+id+", Name="+name;
	}
	public static void main(String[] args) {
		JournalDevTest d = new JournalDevTest();
		System.out.println(d);
		
		d = new JournalDevTest("Java");
		System.out.println(d);
		
		d = new JournalDevTest("Pankaj", 25);
		System.out.println(d);
		
	}

}
