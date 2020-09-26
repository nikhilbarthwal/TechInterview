module Base

open System

exception Error of string

type Config(dir: string) =
    let id = (System.Guid.NewGuid()).ToString().ToUpper()
    let timeStamp = System.DateTime.Now.ToString("F")
    member this.Location() = dir
    member this.Id = id
    member this.Timestamp = timeStamp
    static member mail: string = "tech.interview@gmail.com"
    static member Title = "Tech Interviews"
    static member Tab = "\t"

let combine (l:string list list) =
    let tail: string list list = l.Tail |> List.map (fun x -> ""::x)
    (l.Head)::tail |> List.concat


let head (title: string option) : string list =
    let t: string = match title with Some(x) -> x + " - " + Config.Title | None -> Config.Title
    ["<head>";
    Config.Tab + "<title>" + t + "</title>";
    Config.Tab + "<meta charset=\"utf-8\"/>";
    Config.Tab + "<meta content=\"width=device-width, initial-scale=1, user-scalable=no\" name=\"viewport\"/>";
    Config.Tab + "<link href=\"assets/css/main.css\" rel=\"stylesheet\"/>";
    "</head>"]

let scripts : string list = [
    "<!-- Scripts -->";
    "<script src=\"js/jquery.min.js\"></script>";
    "<script src=\"js/browser.min.js\"></script>";
    "<script src=\"js/breakpoints.min.js\"></script>";
    "<script src=\"js/util.js\"></script>";
    "<script src=\"js/main.js\"></script>"]

let footer timestamp: string = "<footer id=\"footer\"><p class=\"copyright\">Last update: " + timestamp + "</p></footer>"

let rec repeat s n = if (n<0) then raise (Error("Negative argument to Repeat")) else (if (n=0) then "" else s + (repeat s (n-1)))

let intend (n: int) (l: string list) = l |> List.map (fun x-> x + (repeat Config.Tab n))
