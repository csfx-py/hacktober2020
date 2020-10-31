public class AffineCipher {

			static int a = 17; 
			static int b = 20; 

			static String encryptMessage(char[] msg) 
			{ 
				String cipher = ""; 
				for (int i = 0; i < msg.length; i++) 
				{ 
					if (msg[i] != ' ') 
					{ 
						cipher = cipher + (char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A'); 
					} 
					else  
					{ 
						cipher += msg[i]; 
					} 
				} 
				return cipher; 
			} 

			static String decryptCipher(String cipher) 
			{ 
				String msg = ""; 
				int a_inv = 0; 
				int flag = 0; 

				for (int i = 0; i < 26; i++) 
				{ 
					flag = (a * i) % 26; 

					if (flag == 1) 
					{ 
						a_inv = i; 
					} 
				} 
				
				for (int i = 0; i < cipher.length(); i++) 
				{ 
					if (cipher.charAt(i) != ' ') 
					{ 
						msg = msg + (char) (((a_inv *((cipher.charAt(i) + 'A' - b)) % 26)) + 'A'); 
					} 
					else  
					{ 
						msg += cipher.charAt(i); 
					} 
				} 

				return msg; 
			} 

			public static void main(String[] args) 
			{ 
				String msg = "HELLO"; 

				String cipherText = encryptMessage(msg.toCharArray()); 
				System.out.println("Encrypted Message is : " + cipherText); 

				System.out.println("Decrypted Message is: " + decryptCipher(cipherText)); 

			} 
		}
