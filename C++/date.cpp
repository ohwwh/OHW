class date{
	int _year;
	int _month;
	int _day;

	public:
		void SetDate(int year, int month, int date);
		void AddDay(int inc);
		void Addmonth(int inc);
		void AddYear(int inc);
		void ShowDate();

		date(int year, int month, int date)
		{
			_year = year;
			_month = month;
			_day = date;
		}

		void SetDate(int year, int month, int date)
		{
			_year = year;
			_month = month;
			_day = date;
		}
		void AddDay(int inc);
		void Addmonth(int inc);
		void AddYear(int inc);
		void ShowDate();
};

int main()
{
	date ndate = new date();
}