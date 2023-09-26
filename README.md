# fractalsKoch

Instructions for running the program:

    The program is quite intuitive and directly asks the user for input. The program itself prompts for what needs to be defined within it.
    To specify the replacement rule, the user doesn't need to identify the rule explicitly (For example: F = -F+F+FF, or F -> -F+F+FF); you only need to enter the rule as -F+F+FF. The same goes for fractals that have X and Y rules (For example: X = -X+FY, or X -> -X+FY); you only need to enter the rule as -X+FY.
    The programs are already predefined to calculate the 4 stages for all fractals.

    Sinusoidal Wave 2 of Koch
Run the program.

The program will ask the user to:

    Provide the corresponding Fractal Number
    Provide the Axiom
    Provide the Angle in degrees
    Provide the Rule

At the end, the program will indicate that the generated sequence has been saved in the output file. The final output file will be named:
"exit_wavesinusoidal.txt"



    Hilbert Curve 

Run the program.

The program will ask the user to:

    Provide the corresponding Fractal Number
    Provide the Axiom
    Provide the Angle in degrees
    Provide the Rule for X
    Provide the Rule for Y

At the end, the program will indicate that the generated sequence has been saved in the output file. The final output file will be named:
"exit_hilbert.txt"



    Custom Fractal 

Run the program. The corresponding inputs are defined below.

The program will ask the user to:

    Provide the Axiom: X
    Provide the Angle in Degrees: 75
    Provide the Rule for X: +FY-XFX-YF+
    Provide the Rule for Y: -FX+YFY+XF-

At the end, the program will indicate that the generated sequence has been saved in the output file. The final output file will be named:
"my_fractal.txt"

Output Format:

The outputs of each program are saved in the corresponding file with the following structure:

Fractal Title

Corresponding Fractal Number: Fractal identification number provided by the user (except for the custom fractal)
Axiom: Axiom provided by the user
Angle in Degrees: Angle in degrees provided by the user
Rule: Rule defined by the user

Symbol Sequence in the 1st Stage:
XXXXXXXX

Symbol Sequence in the 2nd Stage:
XXXXXXXXXXXXXXXXXXXXX

Symbol Sequence in the 3rd Stage:
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Symbol Sequence in the 4th Stage:
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Note: The 'X' above represents the symbols 'F', '+', '-' that will be printed.
