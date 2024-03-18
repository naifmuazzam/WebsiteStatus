# Website STATUS

C program that allows to check the status and response time of a website. It utilizes the `ping` command to send a single ICMP echo request packet to the specified website and displays the response time, indicating whether the website is UP or DOWN.

## WebStats Features

- Checks internet connection before proceeding.
- Allows users to input the website they want to check.
- Displays whether the website is up or down along with the response time (if available).

## Prerequisites

- This program is designed to work on Unix-like systems (e.g., Linux, macOS)
- Ensure you have `gcc` compiler installed to compile the C program.

## Usage

1. Compile the program using the following command: `gcc webstats.c -o webstats`
2. Run the compiled program: `./webstats`
3. Follow the prompts to enter the website you want to check.

# License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

[KraKeN]

## Acknowledgments

- Quickly check website status.
- Thanks ChatGPT for assisting in creating this README.md file.
