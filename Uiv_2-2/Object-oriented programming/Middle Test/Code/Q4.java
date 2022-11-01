class Gate {
	protected boolean x, y;

	public Gate(boolean x, boolean y) {
		this.x = x;
		this.y = y;
	}

	public boolean operation() {
		return true;
	}

	public String operator() {
		return null;
	}
}

class andGate extends Gate{
	andGate(boolean x, boolean y){
		super(x,y);
	}
	public boolean operation() {
		return x&y;
	}
	public String operator() {
		return x + " & " + y;
	}
}

class orGate extends Gate{
	orGate(boolean x, boolean y){
		super(x,y);
	}
	public boolean operation() {
		return x|y;
	}
	public String operator() {
		return x + " | " + y;
	}
}

class xorGate extends Gate{
	xorGate(boolean x, boolean y){
		super(x,y);
	}
	public boolean operation() {
		return x^y;
	}
	public String operator() {
		return x + " ^ " + y;
	}
}

public class Q4 {
	public static void main(String[] args) {
		Gate[] gate = { new andGate(true, false),
				new orGate(true, false),
				new xorGate(true, false) };
		for (Gate g : gate) {
			System.out.println(g.operator() + " = " + g.operation());
		}
	}
}
