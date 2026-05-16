class Median
{
public:
  multiset<int> start, end;
  int suml = 0, sumg = 0;
  void insert(int n)
  {
    end.insert(n);
    sumg += n;
    balance();
  }
  void remove(int n)
  {
    auto it = start.find(n);
    if (it == start.end())
    {
      end.erase(end.find(n));
      sumg -= n;
    }
    else
    {
      start.erase(it);
      suml -= n;
    }
    balance();
  }
  void balance()
  {
    while (!end.empty() && !start.empty() && *end.begin() < *start.rbegin())
    {
      int temp = *end.begin();
      sumg -= temp;
      end.erase(end.begin());
      suml += temp;
      start.insert(temp);
    }
    while (start.size() < end.size())
    {
      int temp = *end.begin();
      suml += temp;
      start.insert(temp);
      sumg -= temp;
      end.erase(end.begin());
    }
    while (start.size() - end.size() > 1)
    {
      int temp = *prev(start.end());
      end.insert(temp);
      sumg += temp;
      suml -= temp;
      start.erase(prev(start.end()));
    }
  }
  int getMedian()
  {
    return *this->start.rbegin();
  }
};
