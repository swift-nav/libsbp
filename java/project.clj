(defproject io.swiftnav/sbp "0.1.1-SNAPSHOT"

  :deploy-repositories
  {"releases"
   {:url "https://oss.sonatype.org/service/local/staging/deploy/maven2/"
    :creds :gpg}
   "snapshots"
   {:url "https://oss.sonatype.org/content/repositories/snapshots/"
    :creds :gpg}}

  :url "https://github.com/swift-nav/libsbp"

  :description "Java client for Swift Binary Protocol (SBP)."

  :license {:name "LGPLv3.0"}

  :dependencies [[org.codehaus.preon/preon-io "1.1-SNAPSHOT"]
                 [org.codehaus.preon/preon-binding "1.1-SNAPSHOT"]
                 [org.codehaus.preon/preon-el "1.1-SNAPSHOT"]
                 [org.codehaus.preon/preon-emitter "1.1-SNAPSHOT"]]
  :profiles {:dev
             {:dependencies
              [[org.clojure/clojure "1.7.0-alpha5"]]}}

  :java-source-paths ["src"]

  :javac-options ["-target" "1.6" "-source" "1.6"]

  :scm {:url "git@github.com:swiftnav-nav/libsbp.git"}

  :repositories [["codehaus-snapshots"
                  {:url "http://nexus.codehaus.org/snapshots/"}]]

  :classifiers {:javadoc {:java-source-paths ^:replace []
                          :source-paths ^:replace []
                          :resource-paths ^:replace []}
                :sources {:java-source-paths ^:replace []
                          :resource-paths ^:replace []}})
