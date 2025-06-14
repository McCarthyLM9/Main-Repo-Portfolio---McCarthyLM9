"""
Weather App GUI using Tkinter and OpenWeatherMap API.

Fetches and displays current weather for a given city.
"""

import os
import tkinter as tk
from tkinter import messagebox
import requests
from dotenv import load_dotenv

load_dotenv()


class WeatherApp:
    """
       Tkinter GUI app to fetch and display weather
       info using OpenWeatherMap API.
    """

    def __init__(self, master):
        """Initialize the GUI elements and set up the API key."""
        self.master = master
        master.title("Weather App")
        master.resizable(False, False)

        self.api_key = os.getenv("WEATHER_API_KEY")
        if not self.api_key:
            messagebox.showerror(
                "API Key Error",
                "API key not found. Set WEATHER_API_KEY in .env"
            )
            master.destroy()
            return
        self.base_url = "https://api.openweathermap.org/data/2.5/weather"

        # GUI Elements
        tk.Label(master, text="Enter City Name:").pack(pady=5)

        self.city_entry = tk.Entry(master, width=30)
        self.city_entry.pack(pady=5)

        self.get_weather_button = tk.Button(
            master, text="Get Weather", command=self.get_weather
        )
        self.get_weather_button.pack(pady=10)

        self.result_text = tk.Text(master, height=8, width=40, padx=10, pady=5)
        self.result_text.pack(pady=5)
        self.result_text.config(state=tk.DISABLED)

    def get_weather(self):
        """Fetch weather data from API and update the GUI with the results."""
        city = self.city_entry.get().strip()
        if not city:
            messagebox.showwarning("Input Error", "Please enter a city name.")
            return

        params = {
            "q": city,
            "appid": self.api_key,
            "units": "imperial"
        }

        try:
            response = requests.get(self.base_url, params=params, timeout=5)
            response.raise_for_status()
        except requests.RequestException as e:
            messagebox.showerror("Request Failed", f"Failed to get data:\n{e}")
            return

        data = response.json()
        if data.get("cod") != 200:
            messagebox.showerror(
                "Error", data.get("message", "Error fetching weather data")
            )
            return

        weather_info = (
            f"Weather in {data['name']}:\n"
            f"Temperature: {data['main']['temp']}°F\n"
            f"Description: {data['weather'][0]['description'].capitalize()}\n"
            f"Humidity: {data['main']['humidity']}%\n"
            f"Wind Speed: {data['wind']['speed']} mph"
        )

        self.result_text.config(state=tk.NORMAL)
        self.result_text.delete(1.0, tk.END)
        self.result_text.insert(tk.END, weather_info)
        self.result_text.config(state=tk.DISABLED)


def main():
    """Create the main window and start the Tkinter event loop."""
    root = tk.Tk()
    WeatherApp(root)
    root.mainloop()


if __name__ == "__main__":
    main()
