"""main module for the StatsCalculator project.
   This module reads a file name from the command line, processes the data
   using the StatsCalculator class, and prints summary statistics.
"""
import sys
from stats_calculator import StatsCalculator


def main():
    """Main function to run the StatsCalculator with command line arguments."""
    if len(sys.argv) < 2:
        print(
            "ERROR: Please specify a file name at the command line.",
            file=sys.stderr
        )
        sys.exit(1)

    file_name = sys.argv[1]

    try:
        calculator = StatsCalculator(file_name)

        print()
        print(f"Summary Statistics for {file_name}")
        print("-------------------------------------------")
        print(f"n:      {calculator.get_sample_size()}")
        print(f"Mean:   {calculator.estimate_mean():.4g}")

        try:
            stddev = calculator.estimate_standard_deviation()
            print(f"StdDev: {stddev:.4g}")
        except ValueError as e:
            print(e, file=sys.stderr)

        print(f"Max:    {calculator.find_max():.4g}")
        print(f"Min:    {calculator.find_min():.4g}")
        print()

    except IOError as e:
        print(f"File Error: {e}", file=sys.stderr)
        sys.exit(1)
    except ValueError as e:
        print(f"Data Error: {e}", file=sys.stderr)
        sys.exit(1)

    sys.exit(0)


if __name__ == "__main__":
    sys.exit(main())
