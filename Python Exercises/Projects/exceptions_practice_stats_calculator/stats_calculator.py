"""stats calculator module for reading numbers
   from a file and calculating statistics
"""
import math
from pathlib import Path


class StatsCalculator:
    """gets sample size, mean, standard deviation, max, min"""
    def __init__(self, file_name):
        self.number_list = []

        project_path = Path(__file__).parent.resolve()
        file_path = project_path / file_name.strip()

        try:
            with file_path.open('r', encoding='utf-8') as input_file:
                content = input_file.read()
                if not content.strip():
                    raise IOError(f"File {file_name} is empty")

                input_file.seek(0)
                for line_num, line in enumerate(input_file, start=1):
                    for part in line.split():
                        try:
                            num = float(part)
                            self.number_list.append(num)
                        except ValueError:
                            print(
                                f"Warning: Skipping invalid input: '{part}'"
                                f" (line {line_num})"
                            )

            if not self.number_list:
                raise ValueError(f"No valid numbers found in file {file_name}")

        except FileNotFoundError as e:
            raise IOError(f"Could not open file '{file_name}'") from e

    def get_sample_size(self):
        """returns sample size"""
        return len(self.number_list)

    def estimate_mean(self):
        """returns mean"""
        if not self.number_list:
            raise ValueError("Cannot calculate mean: no data available")
        return sum(self.number_list) / self.get_sample_size()

    def estimate_standard_deviation(self):
        """returns sample standard deviation"""
        n = self.get_sample_size()
        if n < 2:
            raise ValueError(
                "Cannot calculate standard deviation: n < 2"
            )
        mean = self.estimate_mean()
        variance = sum((x - mean) ** 2 for x in self.number_list) / (n - 1)
        return math.sqrt(variance)

    def find_max(self):
        """returns max"""
        if not self.number_list:
            raise ValueError("Cannot find max: no data available")
        return max(self.number_list)

    def find_min(self):
        """returns min"""
        if not self.number_list:
            raise ValueError("Cannot find min: no data available")
        return min(self.number_list)
