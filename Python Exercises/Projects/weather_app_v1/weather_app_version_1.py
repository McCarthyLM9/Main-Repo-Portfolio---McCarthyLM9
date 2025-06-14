"""Weather App: Fetch current weather using OpenWeatherMap API."""
import os
import requests
from dotenv import load_dotenv

load_dotenv()  # Load environment variables from .env file


class WeatherApp:
    """A class to fetch and display weather information for a given city."""

    def __init__(self):
        """Initialize the WeatherApp with an API key."""
        self.api_key = os.getenv("WEATHER_API_KEY")
        if not self.api_key:
            raise ValueError(
                "API key not found. Set the "
                "WEATHER_API_KEY environment variable in your .env file."
            )
        self.base_url = "https://api.openweathermap.org/data/2.5/weather"

    def get_weather(self, city):
        """Get weather data for a given city."""
        params = {
            "q": city,
            "appid": self.api_key,
            "units": "imperial"
        }

        try:
            response = requests.get(self.base_url, params=params, timeout=5)
            response.raise_for_status()  # raise exception for HTTP errors
        except requests.RequestException as e:
            print(f"Request failed: {e}")
            return None

        data = response.json()
        return {
            "city": data.get("name"),
            "temperature": data["main"]["temp"],
            "description": data["weather"][0]["description"],
            "humidity": data["main"]["humidity"],
            "wind_speed": data["wind"]["speed"]
        }


def main():
    """Main function to run the weather app."""
    app = WeatherApp()
    city = input("Enter city name: ").strip()
    weather = app.get_weather(city)

    if weather:
        print(f"\nWeather in {weather['city']}:")
        print(f"Temperature: {weather['temperature']}°F")
        print(f"Description: {weather['description'].capitalize()}")
        print(f"Humidity: {weather['humidity']}%")
        print(f"Wind Speed: {weather['wind_speed']} mph")
    else:
        print(
            "Error: Could not retrieve weather data. "
            "Check the city name or API key."
        )


if __name__ == "__main__":
    main()
