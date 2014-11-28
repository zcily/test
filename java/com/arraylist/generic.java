package com.arraylist;

import java.util.ArrayList;
import java.util.Random;
import java.util.Stack;
import java.util.Iterator;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.TreeSet;
import java.util.Arrays;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

class Gerbil
{
	private int gerbilNumber = 0;
	private static int no = 0;

	public Gerbil()
	{
		gerbilNumber = no++;	
	}

	public void hop()
	{
		System.out.print("the gerbil number : " + gerbilNumber);	

		Random rd = new Random();

		int number = rd.nextInt(100);

		if(number % 2 == 0)
			System.out.print("  is jumping");
		else
			System.out.print(" is not jumping");

		System.out.println();
	}

	public String toString()
	{
		return new String("the gerbilNumber " + gerbilNumber);	
	}
}

public class generic
{
	public static void callByiterator(Iterator<Gerbil> it)
	{
		while(it.hasNext())	{
			Gerbil gb = it.next();	
			it.remove();
			gb.hop();
		}
	}
	public static void main(String[] args)
	{
		ArrayList<Gerbil> gerb = new ArrayList<Gerbil>();

		for(int i = 0; i < 10; ++i)
			gerb.add(new Gerbil());
		
		callByiterator(gerb.iterator());

		for(Gerbil gb : gerb) {
			gb.hop();
		}
	}
}

class testStack
{
	private final static String orignalString = "+U+n+c---+e+r+t---+a-+i-+n+t+y---+~+r+u--+1+e+s---";

	public static void main(String[] args)
	{
		Stack<Character> st = new Stack<Character>();
		boolean pushOrPopFlag = true;
		char temp = '0';
		for(int i = 0; i < orignalString.length(); ++i){
			temp = orignalString.charAt(i);
			if(temp == '+') {
				pushOrPopFlag = true;
				continue;
			}else if(temp == '-') {
				pushOrPopFlag = false;	
				System.out.print(st.pop() + " ");	
				continue;
			}

			if(pushOrPopFlag){
				st.push(temp);	
			}
		}
		System.out.println();
	}
}


class setOfInteger
{
	public static void main(String[] args)
	{
		Random rand = new Random();	

		Set<Integer> intset = new HashSet<Integer>();

		for(int i = 0; i < 1000; ++i){
			intset.add(rand.nextInt(30));	
		}

		System.out.println(intset);
	}
}

class unqiueWords
{
	public static void main(String[] args)
	{	
		int oneWordContains = 0;
		int allWordContains = 0;
		int allword = 0;

		Set<Character> yuanYin = new HashSet<Character>();

		Collections.addAll(yuanYin, 'a', 'e', 'i', 'o', 'u');
		
		Set<String> words = new TreeSet<String>(
				new TextFile("com/arraylist/words", "\\W+"));

		Iterator<String> it = words.iterator();

		while(it.hasNext()){
			String tempWord = it.next();
			++allword;

			for(int i = 0; i < tempWord.length(); ++i){
				if(yuanYin.contains(tempWord.charAt(i))){
					++oneWordContains;
				}
			}
			allWordContains += oneWordContains;

			System.out.println("word : " + tempWord + " contains : " + oneWordContains);
			oneWordContains = 0;
			System.out.println();
		}

		System.out.println("there are " + allword + " words  in the file ");
	}
}

class TextFile extends ArrayList<String> {
	private static final long serialVersionUID = 1L;

	//	读文件
	public static String read(String file) {
		StringBuilder builder = new StringBuilder();
		try {
			BufferedReader bf = new BufferedReader(new FileReader(
						new File(file).getAbsoluteFile()));

			try {
				String s = null;
				while ((s = bf.readLine()) != null) {
					builder = builder.append(s);
					builder.append("\n");
				}
			} catch (IOException e) {
				e.printStackTrace();
			} finally {
				try {
					bf.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return builder.toString();
	}

	//	写文件
	public static void write(String file, String content) {
		try {
			PrintWriter pr = new PrintWriter(new File(file).getAbsoluteFile());

			try {
				pr.print(content);
			} finally {
				pr.close();
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	//	根据指定的正则表达式拆分文件
	public TextFile(String file, String regex) {
		super(Arrays.asList(read(file).split(regex)));
		if (get(0).equals(""))
			remove(0);
	}

	//	读文件
	public TextFile(String file) {
		this(file, "\n");
	}

	//	写文件
	public void write(String file) {
		try {
			PrintWriter pw = new PrintWriter(new File(file).getAbsoluteFile());

			try {
				for (String item : this) {
					pw.print(item);
				}
			} finally {
				pw.close();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		String file = read("D:IAReg.txt");
		System.out.println(file);

		write("D:b.txt", file);

		TextFile tf = new TextFile("D:b.txt");

		tf.write("D:c.txt");

		TextFile tf2 = new TextFile("D:b.txt", "\\W+");
		System.out.println(tf2);
	}
}
