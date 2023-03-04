use std::io;
use std::process::Command;
use std::env::consts::OS;
use std::fs::File;
use std::io::prelude::*;

fn main()
{
    loop 
    {
        println!("1. Register\n2. Login");
        let option = input("");
        clear();
        match &option[..] // Getting a slice of the string
        {
            "1" =>
            {
                println!("Enter username: ");
                let username = input("");
                let file_path = "assets/".to_string() + &username + ".txt";
                if let Ok(mut check_file) = File::open(&file_path)
                {
                    println!("!-- This account already exists --!");
                    continue;
                }
                println!("Enter password: ");
                let password = input("");
                let mut file = File::create(&file_path).expect("!?-- There is a error creating the file! --?!");
                File::write(&mut file, username.as_bytes()).expect("!?-- Cannot write to file (username) --?!");
                File::write(&mut file, b" ").expect("!? -- Cannot write to the file (whitespace) --?!");
                File::write(&mut file, password.as_bytes()).expect("!?-- Cannot write to the file (password) --?!");
            }
            "2" =>
            {
                println!("Enter the username: ");
                let username = input("");
                let file_path = "assets/".to_string() + &username + ".txt";
                if let Err(_) = File::open(&file_path)
                {
                    println!("!-- This account doesnt exist --!");
                    continue;
                }
                println!("Enter password: ");
                let password = input("");
                let mut file = File::open(&file_path)
                                 .expect("!?-- Cannot open file --?!");
                let mut contents = String::new();
                file.read_to_string(&mut contents).expect("!?-- Cannot read file --?!");
                let parts:Vec<&str> = contents.trim().split(" ").collect();
                let a_password = parts[1];
                if(password == a_password)
                {
                    println!("Hi, welcome to our app!");
                    return;
                }
                else
                {
                    println!("!-- Not the right password --!");
                }


            }
            _ =>
            {
                println!("!-- {} is not a option --!", option);
            }
        }
    }
}

// input function that is kinda like the input function in Python
fn input(question: &str) -> String
{
    let mut string:String = String::new();
    print!("{}", question);
    io::stdin().read_line(&mut string).expect("Cannot read line!");
    return (string.trim_end()).to_string();
}


// The function to clear the terminal(command prompt) 
fn clear()
{
    // Matching on the OS of the user
    match OS
    {
        "windows" =>
        {
            // We use "cls" for windows because this is the way to clear in windows
            let _ = Command::new("cmd")
                             .args(&["/C", "cls"])
                             .status();
        }
        _ =>
        {
            // We use "clear" for any other OS like Unix/Linux/MacOS
            let _ = Command::new("clear")
                           .status();
        }
    }
}