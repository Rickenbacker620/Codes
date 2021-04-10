using System;
using System.Threading.Tasks;

namespace Comic
{
    class Program
    {
        static async Task Main(string[] args)
        {
            ComicDownloader comic = new();
            await comic.Run();
        }
    }
}
