#include <bits/stdc++.h>
using namespace std;

int ans = 0;
pair<int, char> card[5];
pair<char, int> cardByColor[5];
bool color = true, straight = true;

bool one()
{
	if (!color || !straight) return false;
	ans = card[4].first + 900;
	return true;
}

bool two()
{
	if (card[0].first == card[3].first || card[1].first == card[4].first)
	{
		ans = card[2].first + 800;
		return true;
	}
	return false;
}

bool three()
{
	if (card[0].first == card[1].first && card[2].first == card[4].first)
	{
		ans = card[4].first * 10 + card[0].first + 700;
		return true;
	}
	if (card[0].first == card[2].first && card[3].first == card[4].first)
	{
		ans = card[0].first * 10 + card[4].first + 700;
		return true;
	}
	return false;
}

bool four()
{
	if (!color) return false;
	ans = card[4].first + 600;
	return true;
}

bool five()
{
	if (!straight) return false;
	ans = card[4].first + 500;
	return true;
}

bool six()
{
	if (card[0].first == card[2].first || card[1].first == card[3].first || card[2].first == card[4].first)
	{
		ans = card[2].first + 400;
		return true;
	}
	return false;
}

bool seven()
{
	if (card[0].first == card[1].first)
	{
		if (card[2].first == card[3].first || card[3].first == card[4].first)
		{
			ans = card[3].first * 10 + card[0].first + 300;
			return true;
		}
	}
	if (card[1].first == card[2].first && card[3].first == card[4].first)
	{
		ans = card[3].first * 10 + card[1].first + 300;
		return true;
	}
	return false;
}

bool eight()
{
	for(int i = 1; i <= 4; i++)
	{
		if (card[i].first == card[i - 1].first)
		{
			ans = card[i].first + 200;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= 4; i++)
	{
		cin >> card[i].second >> card[i].first;
		cardByColor[i] = { card[i].second, card[i].first };
	}
	sort(card, card + 5);
	sort(cardByColor, cardByColor + 5);
	if (cardByColor[0].first != cardByColor[4].first) color = false;
	for (int i = 1; i <= 4; i++)
	{
		if (card[i].first != card[i - 1].first + 1) straight = false;
	}

	if (one()) {}
	else if (two()) {}
	else if (three()) {}
	else if (four()) {}
	else if (five()) {}
	else if (six()) {}
	else if (seven()) {}
	else if (eight()) {}
	else ans = card[4].first + 100;
	cout << ans;

	return 0;
}