


import java.util.regex.Pattern;
import java.text.DecimalFormat;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
/**
 * @author kunalkp
 */
public class compute_a_posteriori {

    /**
     * @param args
     */
      private static DecimalFormat df5 = new DecimalFormat("##.#####");


    final static double preh1 = 0.1;
    final static double preh2 = 0.2;
    final static double preh3 = 0.4;
    final static double preh4 = 0.2;
    final static double preh5 = 0.1;
    public static void main(String[] args)throws IOException {
      BufferedWriter writer = new BufferedWriter(new FileWriter( "results.txt"));
        String tmp="";
        if( args.length > 1 ) 
        {
          System.out.println("Wrong usage of the program, pease use : java compute_a_posteriori <string>\n");
 System.out.println("Exiting from program");
 System.exit( 0 );
         
         }
        
        else if(args.length == 0)
        {
            System.out.println("Observation Sequence Q is 0" );
            System.out.println("Hence length of Q: 0 \n Calculating :\n");
                    writer.write("Observation Sequence Q: 0");
        writer.newLine();
        writer.write("Hence length of Q : 0");
        writer.newLine();
writer.close();
            calculateAnswer(0,0);
        }
        else
            {
            tmp = args[0];
            if (args[0] == null || Pattern.matches("[\\dLC]+", tmp) )
            {}
                else
                {
                    System.out.println("String with L/ C allowed only");
                     System.out.println("Exiting from program");
                     System.exit( 0 );
                   
             }

  int Lctr=0,Cctr=0;
for(int i=0;i< tmp.length();i++)
{
  if(tmp.charAt(i) == 'C')
{ Cctr++;}
    else if(tmp.charAt(i) == 'L')
    {Lctr++;}
}

        
        System.out.println("Observation Sequence Q: " + tmp);
        System.out.println("Hence length of Q: " + args[0].length() + "\n");
        writer.write("Observation Sequence Q: " + tmp);
        writer.newLine();
        writer.write("Hence length of Q: " + args[0].length());
        writer.newLine();

        calculateAnswer(Cctr,Lctr);
            }
    }
      
      private static void calculateAnswer (int Cctr , int Lctr)throws IOException
      {BufferedWriter writer = new BufferedWriter(new FileWriter( "results.txt",true));
                    double lhood_h1 = (Math.pow(1, Cctr)) * (Math.pow(0.0, Lctr));
                    double lhood_h2 = (Math.pow(0.75, Cctr)) * (Math.pow(0.25, Lctr));
                    double lhood_h3 = (Math.pow(0.5, Cctr)) * (Math.pow(0.50, Lctr));
                    double lhood_h4 = (Math.pow(0.25, Cctr)) * (Math.pow(0.75, Lctr));
                    double lhood_h5 = (Math.pow(0.00, Cctr)) * (Math.pow(1, Lctr));
//////////////////////////////////////////////////

                    double pstr_h[] = new double[7];
                     pstr_h[1] = preh1 * lhood_h1;
                     pstr_h[2] = preh2 * lhood_h2;
                     pstr_h[3] = preh3 * lhood_h3;
                     pstr_h[4] = preh4 * lhood_h4;
                     pstr_h[5] = preh5 * lhood_h5;
///////////////////////////////////////
                    double abc = pstr_h[1] + pstr_h[2]+ pstr_h[3] + pstr_h[4] + pstr_h[5];

                    for(int i=1;i<=5;i++)
                    {
                    pstr_h[i] /= abc;
                    }

                    double nextC = 1 * pstr_h[1] + 0.75 * pstr_h[2] + 0.5 * pstr_h[3] + 0.25 * pstr_h[4] + 0 * pstr_h[5];
                    double nextL = 0 * pstr_h[1] + 0.25 * pstr_h[2] + 0.5 * pstr_h[3] + 0.75 * pstr_h[4] + 1 * pstr_h[5];
System.out.println("Printing answer");
                    
                    for(int j=1;j<=5;j++)
                    {writer.write("p(h" + j);
                      //writer.write((char)j);
                      writer.write(" | Q) = ");
                      writer.write(df5.format(pstr_h[j]));
                      writer.newLine();
                    }

                      writer.write("Probability that the next candy we pick will be C, given Q:  = ");
                      writer.write(df5.format(nextC));
                      writer.newLine();
                      writer.write("Probability that the next candy we pick will be L, given Q:  = ");
                      writer.write(df5.format(nextL));
                      writer.newLine();
                    writer.close();
      }
      

}
