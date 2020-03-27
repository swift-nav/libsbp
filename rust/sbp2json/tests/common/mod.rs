pub fn find_project_root() -> Option<std::path::PathBuf> {
    let exe = std::env::current_exe();
    assert!(exe.is_ok());
    let mut path = exe.unwrap();
    loop {
        let parent = path.parent();
        if let Some(parent) = parent {
            let git_dir = parent.join(".git");
            if git_dir.exists() {
                return Some(parent.to_path_buf());
            } else {
                path = parent.to_path_buf();
            }
        } else {
            break;
        }
    }
    return None;
}
