using System;
using System.IO;

namespace App
{
    class Project
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("1. Register\n2. Login");
                string option = Console.ReadLine();
                Console.Clear();
                if(option == "1")
                {
                    Console.WriteLine("Enter username: ");
                    string username = Console.ReadLine();
                    string file_path = $"assets/{username}.txt";
                    if(File.Exists(file_path))
                    {
                        Console.WriteLine("!-- This account already exists --!");
                        continue;
                    }

                    Console.WriteLine("Enter password: ");
                    string password = Console.ReadLine();
                    try
                    {
                        StreamWriter sw = new StreamWriter(file_path);
                        sw.Write($"{username} {password}");
                        sw.Dispose();
                    }
                    catch (System.Exception)
                    {
                        Console.WriteLine($"!?-- Cannot create a account {username} --?!");
                    }
                    
                }
                else if(option == "2")
                {
                    Console.WriteLine("Enter the username");
                    string username = Console.ReadLine();
                    string file_path = $"assets/{username}.txt";
                    if(!File.Exists(file_path))
                    {
                        Console.WriteLine($"!-- There is no account name {username} --!");
                        continue;
                    }

                    try
                    {
                        StreamReader sr = new StreamReader(file_path);
                        string user = sr.ReadLine();
                        string[] parts = user.Split(' ');

                        Console.WriteLine("Enter password: ");
                        string password = Console.ReadLine();

                        if(password == parts[1])
                        {
                            Console.WriteLine("Welcome to our app!");
                            Console.Beep();
                            return;
                        }
                        else
                        {
                            Console.WriteLine("!-- Not the right password --!");
                        }
                        sr.Dispose();
                    }
                    catch
                    {
                        Console.WriteLine($"!?-- Cannot read from file with path {file_path}");
                        continue;
                    }
                }
                else
                {
                    Console.WriteLine("Default");
                }
            }
        }
    }
}