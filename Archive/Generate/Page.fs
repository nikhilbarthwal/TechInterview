module Page

open Base

[<AbstractClass>]
type Page(config: Config) =

    abstract member title : string
    abstract member filename : string
    abstract member menuItem: string list

    member this.menu (pages: Page list): string list = pages |> List.map (fun (x:Page) -> x.menuItem) |> List.concat

    member this.render (pages: Page list) (config: Config) =
        let tab = Config.Tab
        let contents: string list = this.menu pages
        System.IO.File.WriteAllLines (this.filename, List.toArray contents)
