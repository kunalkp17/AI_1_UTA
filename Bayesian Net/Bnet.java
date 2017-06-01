
import java.util.ArrayList;

public class Bnet {

	Node A;
	Node B;
	Node E;
	Node J;
	Node M;
	
	public Bnet() {
		B = new Node('B', Node.NodeLocation.INITIAL);
		E = new Node('E', Node.NodeLocation.INITIAL);
		A = new Node('A', Node.NodeLocation.INTERMEDIATE);
		J = new Node('J', Node.NodeLocation.END);
		M = new Node('M', Node.NodeLocation.END);
	}
	
	public void setValueTrue(Node tmp, boolean givenCheck) {
		tmp.query_end = 0;
		if (givenCheck == true) {
			tmp.given_end = 0;
		} 
	}
	
	public void setValueFalse(Node tmp, boolean givenCheck) {
		tmp.query_beg = 1;
		if (givenCheck == true) {
			tmp.given_beg = 1;
		} 
	}
	
	public void readFromCMD(String[] args) {
		boolean givenCheck = false;
		
		for (int i = 0; i < args.length; i++) {
			if (args[i].equalsIgnoreCase("given")) {
				givenCheck = true;
			} else if (args[i].equalsIgnoreCase("Bt")) {
				setValueTrue(this.B, givenCheck);
			} else if (args[i].equalsIgnoreCase("Bf")) {
				setValueFalse(this.B, givenCheck);
			} else if (args[i].equalsIgnoreCase("Et")) {
				setValueTrue(this.E, givenCheck);
			} else if (args[i].equalsIgnoreCase("Ef")) {
				setValueFalse(this.E, givenCheck);
			} else if (args[i].equalsIgnoreCase("At")) {
				setValueTrue(this.A, givenCheck);
			} else if (args[i].equalsIgnoreCase("Af")) {
				setValueFalse(this.A, givenCheck);
			} else if (args[i].equalsIgnoreCase("Jt")) {
				setValueTrue(this.J, givenCheck);
			} else if (args[i].equalsIgnoreCase("Jf")) {
				setValueFalse(this.J, givenCheck);
			} else if (args[i].equalsIgnoreCase("Mt")) {
				setValueTrue(this.M, givenCheck);
			} else if (args[i].equalsIgnoreCase("Mf")) {
				setValueFalse(this.M, givenCheck);
			} else {
				System.out.println("Wrong input term, please follow the rules of input.");
				System.exit(0);
			}
		}
		
		
	}
	
	public static double computeProbability (Node B, Node E, Node A, Node J, Node M) {
			
		
			//Our numerator is search
			double numerator = 0;
			for (int b = B.query_beg; b <= B.query_end; b++) { 															//Burglary
				for (int e = E.query_beg; e <= E.query_end; e++) {														
					for (int a = A.query_beg; a <= A.query_end; a++) { 													//Alarm
						for (int j = J.query_beg; j <= J.query_end; j++) { 												//John calls
							for (int m = M.query_beg; m <= M.query_end; m++) { 											//Mary calls
								numerator = numerator + (Node.findProb(B, b, -1, -1) * Node.findProb(E, e, -1, -1) * Node.findProb(A, a, b, e) * Node.findProb(J, j, a, -1) * Node.findProb(M, m, a, -1));
								
							}
						}
					}
				}
			}

			//Our denominator is given 
			double denominator = 0;
			for (int b = B.given_beg; b <= B.given_end; b++) { 												//Burglary
				for (int e = E.given_beg; e <= E.given_end; e++) {											//Earthquake
					for (int a = A.given_beg; a <= A.given_end; a++) { 										//Alarm
						for (int j = J.given_beg; j <= J.given_end; j++) { 									//John calls
							for (int m = M.given_beg; m <= M.given_end; m++) { 								//Mary calls
								denominator = denominator + (Node.findProb(B, b, -1, -1) * Node.findProb(E, e, -1, -1) * Node.findProb(A, a, b, e) * Node.findProb(J, j, a, -1) * Node.findProb(M, m, a, -1));
								
							}
						}
					}
				}
			}
			
			System.out.println("The answer is :");
			System.out.println("Numerator: " + numerator);
			System.out.println("Denominator: " + denominator);
			
			return (numerator/denominator);
	}
	
	
	public static void main(String[] args) {
		
		if (args.length == 0) {
			System.out.println("Input some args");
			System.exit(0);
		}
		if (args.length > 6) {
			System.out.println("Input between 1 and 5 args in command line");
			System.exit(0);
		}
		
		Bnet obj = new Bnet();
		obj.readFromCMD(args);
		
		double answer = computeProbability(obj.B,obj.E, obj.A, obj.J, obj.M);
		System.out.println("The probability is: " + answer);
		
	}
}
class Node {
	
	public enum NodeLocation {
		INITIAL,
		INTERMEDIATE, 
		END, 
		NONE
	}
	char id;
	NodeLocation loc;
	
	int query_beg;
	int query_end;
	int given_beg;
	int given_end;
	

	//////////////////////////////////////////////////////////////////////////////
	static final double PB = 0.001;
	static final double PE = 0.002;
	static final double PJ_AT = 0.90;
	static final double PJ_AF = 0.05;
	static final double PM_AT = 0.70;
	static final double PM_AF = 0.01;
	static final double PA_BT_ET = 0.95;
	static final double PA_BT_EF = 0.94;
	static final double PA_BF_ET = 0.29;
	static final double PA_BF_EF = 0.001;
	////////////////////////////////////////////////////////////////////////////////
	
	
	public Node(char a, NodeLocation l) {
		id = a;
		loc = l;
		query_beg = 0;
		query_end = 1;
		given_beg = 0; 
		given_end = 1; 
	}
	
	public static double findProb(Node tmp, int val, int p1, int p2) {
	
			double prob= 0;
		
		if (tmp.loc == NodeLocation.INITIAL) { 
			
			if (tmp.id == 'B') { 
				if (val == 1) { 
					prob = PB;
				} else {
					prob =  (1 - PB); 
				}
			}  else { 
				if (val == 1) {
					prob = PE; 
				} else {
					prob = (1 - PE); 
				}
			}
			
		
		} else if (tmp.loc == NodeLocation.INTERMEDIATE) { 
			
			 
			if ((p1 == 1) && (p2 == 1)) { 
				if (val == 1) {
					prob = PA_BT_ET;
				} else {
					prob = (1 - PA_BT_ET); 
				}
				
			} else if ((p1 == 1) && (p2 == 0)) { 
				if (val == 1) {
					prob = PA_BT_EF; 
				} else {
					prob = (1 - PA_BT_EF);
				}
				
			} else if ((p1 == 0) && (p2 == 1)) { 
				if (val == 1) {
					prob = PA_BF_ET; 
				} else {
					prob = (1 - PA_BF_ET);
				}
				
			} else if ((p1 == 0) && (p2 == 0)) { 
				if (val == 1) {
					prob = PA_BF_EF; 
				} else {
					prob = (1 - PA_BF_EF); 
				}
			} 
			
			
		} else if (tmp.loc == NodeLocation.END) { 
			if (tmp.id == 'J') {
				if (p1 == 1) { 
					if (val == 1) {
						prob = PJ_AT; 
					} else {
						prob = (1 - PJ_AT);
					}
				} else { 
					if (val == 1) {
						prob = PJ_AF;
					} else {
						prob = (1 - PJ_AF);
					}
				} 
					
			} else if (tmp.id == 'M') {
				if (p1 == 1) { 
					if (val == 1) {
						prob = PM_AT;  
					} else {
						prob = (1 - PM_AT); 
					}
				} else { 
					if (val == 1) {
						prob = PM_AF;  
					} else {
						prob = (1 - PM_AF);
					}
				} 
			}
		}

		return prob;
			
	}
	
}
