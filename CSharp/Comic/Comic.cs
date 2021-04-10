using System.Net.Http;
using HtmlAgilityPack;
using System.Collections.Generic;
using System;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.IO;

namespace Comic
{
    public class ComicDownloader
    {
        private readonly HttpClient _client = new();

        private string _baseUrl = "https://manhua.fzdm.com/39/";
        private string _baseImgUrl = "https://p5.manhuapan.com/";
        private string _comicName = "Attack On Titan";

        public ComicDownloader()
        {
        }

        private void CreateDirectory(string path)
        {
            if (!Directory.Exists(path))
                Directory.CreateDirectory(path);
        }


        public async Task Run()
        {
            await DownloadChapters(Chapters);
        }

        public async Task DownloadChapters(List<KeyValuePair<string, string>> chapters)
        {
            List<Task> tasks = new();
            foreach (var chapter in chapters)
                tasks.Add(DownloadChapter(chapter));

            await Task.WhenAll(tasks);
        }

        private async Task DownloadChapter(KeyValuePair<string, string> chapter)
        {
            var path = $"{_comicName}/{chapter.Key}/";

            CreateDirectory(path);

            var imgUrls = GetImageUrls(chapter.Value);

            int idx = 0;
            await foreach (var imgUrl in imgUrls)
            {
                var img = await _client.GetByteArrayAsync(imgUrl);
                File.WriteAllBytes($"{path}{idx.ToString()}.jpg", img);
                idx++;
            }
        }

        public List<KeyValuePair<string, string>> Chapters
        {
            get
            {
                var html = new HtmlWeb().Load(_baseUrl);
                var nodes = html.DocumentNode.SelectNodes("//div[@id='content']/li/a");

                List<KeyValuePair<string, string>> chapters = new();
                foreach (var node in nodes)
                {
                    string title = node.InnerText;
                    string url = _baseUrl + node.Attributes["href"].Value;
                    chapters.Add(new(title, url));
                }
                chapters.Reverse();
                return chapters;
            }
        }

        public async Task<string> ExtractImg(string url)
        {
            var res = await _client.GetAsync(url);
            if (!res.IsSuccessStatusCode)
                throw new IndexOutOfRangeException();

            Regex pattern = new(@"(?<=mhurl="").*?(?="";)");
            string rawDoc = await res.Content.ReadAsStringAsync();
            string imgUrl = _baseImgUrl + pattern.Match(rawDoc).Value;
            return imgUrl;
        }

        public async IAsyncEnumerable<string> GetImageUrls(string url)
        {
            int idx = 0;
            while (true)
            {
                string pageUrl = $"{url}index_{idx.ToString()}.html";
                string imgUrl;
                try
                {
                    imgUrl = await ExtractImg(pageUrl);
                }
                catch (IndexOutOfRangeException)
                {
                    break;
                }
                idx++;
                yield return imgUrl;
            }
        }
    }
}