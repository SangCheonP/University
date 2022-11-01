class TV {
	int size;

	TV(int size) {
		this.size = size;
	}

	public int getSize() {
		return size;
	}

	void setSize(int size) {
		this.size = size;
	}
}

class WideTV extends TV {
	boolean videoIn;

	public WideTV(int size, boolean videoIn) {
		super(size);
		this.videoIn = videoIn;
	}

	void setSize(int size) {
		setSize(size);
	}

	boolean getVideoIn() {
		return videoIn;
	}

	void setVideoIn(boolean videoIn) {
		this.videoIn = videoIn;
	}
}

class SmartTV extends TV {
	String ipAddr;

	public SmartTV(int size, String ipAddr) {
		super(size);
		this.ipAddr = ipAddr;
	}

	void setSize(int size) {
		setSize(size);
	}

	String getIpAddr() {
		return ipAddr;
	}

	void setIpAddr(String ipAddr) {
		this.ipAddr = ipAddr;
	}
}

public class Q3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
